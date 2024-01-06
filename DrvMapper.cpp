#include "DrvMapper.h"
#include <vector>
#include "RawDriver.h"

#include "vdm_ctx.h"
#include "drv_image.h"
#include "driver.h"
#include <string>
#include <Windows.h>
#include <random>
#include <string>

bool DrvMapper::MapDriver()
{
	std::string basedriver = XorStr("bxvbda.sys");
	DrvMapper::mappedDriverBase = 0;
	DrvMapper::mappedDriverSize = 0;
	char loadsection[] = ".data";

	if (!util::get_module_base(basedriver.c_str()))
	{
		const auto nt_headers = portable_executable::get_nt_headers(RawDrv.data());

		if (nt_headers->Signature != IMAGE_NT_SIGNATURE)
		{
			return false;
		}

		std::uint32_t image_size = nt_headers->OptionalHeader.SizeOfImage;
		mappedDriverSize = image_size;

		potential_drivers signed_driver = util::get_driver_info(basedriver, loadsection, image_size);

		if (signed_driver.number_of_sections == 0)
		{
			return false;
		}

		NTSTATUS load_status = driver::load(signed_driver.file_path, signed_driver.file_name);
		std::uintptr_t signed_module_base = util::get_module_base(signed_driver.file_name.c_str());

		if ((load_status != STATUS_SUCCESS && load_status != 0x1) || !signed_module_base)
		{
			return false;
		}

		std::uintptr_t start_map = signed_module_base + signed_driver.section_offset;
		mappedDriverBase = start_map;


		static const auto kernel_base = util::get_module_base(XorStr("ntoskrnl.exe"));

		static const auto mm_pte_offset = util::memory::get_mi_pte_address_fn();
		static const auto mm_pde_offset = util::memory::get_mi_pde_address_fn();

		if (!mm_pte_offset || !mm_pde_offset)
		{
			return false;
		}

		const auto [drv_handle, drv_key] = vdm::load_drv();
		if (!drv_handle || drv_key.empty())
		{
			exit(1);
		}

		vdm::vdm_ctx kernel{};

		if (!kernel.clear_piddb_cache(drv_key, util::get_file_header((void*)vdm::raw_driver)->TimeDateStamp))
		{
			vdm::unload_drv(drv_handle, drv_key);
			return false;
		}

		for (std::uintptr_t start = start_map; start < start_map + image_size; start += PAGE_4KB)
		{
			auto pde = kernel.syscall<MiGetPteAddress>(reinterpret_cast<void*>(mm_pde_offset), start);

			::pde new_pde = kernel.rkm<::pde>(pde);

			if (new_pde.large_page)
			{
				new_pde.nx = 0;
				new_pde.rw = 1;

				kernel.wkm<::pde>(pde, new_pde);
			}
			else
			{
				auto pte = kernel.syscall<MiGetPteAddress>(reinterpret_cast<void*>(mm_pte_offset), start);

				::pte new_pte = kernel.rkm<::pte>(pte);

				new_pte.nx = 0;
				new_pte.rw = 1;

				kernel.wkm<::pte>(pte, new_pte);
			}
		}

		void* local_image_base = VirtualAlloc(0, image_size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

		memcpy(local_image_base, RawDrv.data(), nt_headers->OptionalHeader.SizeOfHeaders);

		PIMAGE_SECTION_HEADER current_image_section = IMAGE_FIRST_SECTION(nt_headers);

		for (auto i = 0; i < nt_headers->FileHeader.NumberOfSections; ++i)
		{
			void* local_section = reinterpret_cast<void*>(reinterpret_cast<uint64_t>(local_image_base) + current_image_section[i].VirtualAddress);
			memcpy(local_section, reinterpret_cast<void*>(reinterpret_cast<uint64_t>(RawDrv.data()) + current_image_section[i].PointerToRawData), current_image_section[i].SizeOfRawData);
		}

		portable_executable::relocate_image_by_delta(portable_executable::get_relocations(local_image_base), start_map - nt_headers->OptionalHeader.ImageBase);

		if (!portable_executable::resolve_imports(portable_executable::get_imports(local_image_base)))
		{
			vdm::unload_drv(drv_handle, drv_key);
			return false;
		}

		RtlZeroMemory(local_image_base, nt_headers->OptionalHeader.SizeOfHeaders);
		kernel.wkm(reinterpret_cast<void*>(start_map), local_image_base, image_size);

		std::uintptr_t entry_point = start_map + nt_headers->OptionalHeader.AddressOfEntryPoint;

		NTSTATUS result = kernel.syscall<EntryCall>(reinterpret_cast<void*>(entry_point), start_map, nt_headers->OptionalHeader.SizeOfImage);

		if (!vdm::unload_drv(drv_handle, drv_key))
		{
			return false;
		}

		return true;
	}
}

bool DrvMapper::UnloadDriver(std::uintptr_t driverBase, std::uint32_t driverSize)
{
	static const auto kernel_base = util::get_module_base(XorStr("ntoskrnl.exe"));
	static const auto mm_pte_offset = util::memory::get_mi_pte_address_fn();
	static const auto mm_pde_offset = util::memory::get_mi_pde_address_fn();

	if (!mm_pte_offset || !mm_pde_offset)
	{
		return false;
	}

	vdm::vdm_ctx kernel{};
	for (std::uintptr_t start = driverBase; start < driverBase + driverSize; start += PAGE_4KB)
	{
		auto pde = kernel.syscall<MiGetPteAddress>(reinterpret_cast<void*>(mm_pde_offset), start);
		auto pte = kernel.syscall<MiGetPteAddress>(reinterpret_cast<void*>(mm_pte_offset), start);

		::pde original_pde = kernel.rkm<::pde>(pde);
		::pte original_pte = kernel.rkm<::pte>(pte);

		if (original_pde.large_page)
		{
			kernel.wkm<::pde>(pde, original_pde);
		}
		else
		{
			kernel.wkm<::pte>(pte, original_pte);
		}
	}

	const auto [drv_handle, drv_key] = vdm::load_drv();
	if (!drv_handle || drv_key.empty())
	{
		return false;
	}

	if (!vdm::unload_drv(drv_handle, drv_key))
	{
		return false;
	}

	return true;
}

bool DrvMapper::UnloadBeyondDriver()
{
	return UnloadDriver(DrvMapper::mappedDriverBase, DrvMapper::mappedDriverSize);
}

