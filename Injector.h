#include "Driver.h"
#include "Utils.h"
#include "XorStr.h"
#include "Log.h"

#include "DrvMapper.h"

#include "Definitions.h"
using namespace Definitions;

namespace Injector {

	uintptr_t CallRemoteLoadLibrary(HANDLE pid, DWORD thread_id, LPCSTR dll_name)
	{
		HMODULE nt_dll;
		PVOID AllocatedShellCode;
		DWORD ShellCodeSize;
		PVOID LocalAlloc;

		uintptr_t ShellCodeData;
		HHOOK h_hook;
		uintptr_t ModuleBase;

		nt_dll = LoadLibrary(XorStr("ntdll.dll"));
		AllocatedShellCode = Driver::AllocateProcessMem(pid, 4096, PAGE_EXECUTE_READWRITE);
		ShellCodeSize = sizeof(RemoteLoadLibrary) + sizeof(LoadLibraryStruct);
		LocalAlloc = VirtualAlloc(NULL, ShellCodeSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

		RtlCopyMemory(LocalAlloc, &RemoteLoadLibrary, sizeof(RemoteLoadLibrary));

		ShellCodeData = (uintptr_t)AllocatedShellCode + sizeof(RemoteLoadLibrary);
		*(uintptr_t*)((uintptr_t)LocalAlloc + shell_data_offset) = ShellCodeData;
		LoadLibraryStruct* ll_data = (LoadLibraryStruct*)((uintptr_t)LocalAlloc + sizeof(RemoteLoadLibrary));

		ll_data->fn_load_library_a = (uintptr_t)LoadLibraryA;
		strcpy_s(ll_data->module_name, 80, dll_name);
		Driver::WriteProcessMem(pid, AllocatedShellCode, LocalAlloc, ShellCodeSize);;

		h_hook = SetWindowsHookEx(WH_MOUSE, (HOOKPROC)AllocatedShellCode, nt_dll, thread_id);
		while (ll_data->status != 2)
		{
			Driver::ReadProcessMem(pid, (PVOID)ShellCodeData, (PVOID)ll_data, sizeof(LoadLibraryStruct));
			Sleep(10);
		}

		ModuleBase = ll_data->module_base;
		UnhookWindowsHookEx(h_hook);
		Driver::FreeProcessMem(pid, AllocatedShellCode);
		VirtualFree(LocalAlloc, 0, MEM_RELEASE);
		return ModuleBase;
	}

	void CallDllMain(HANDLE ProcessID, DWORD TheadID, PVOID dll_base, PIMAGE_NT_HEADERS nt_header, bool hide_dll)
	{
		HMODULE nt_dll;
		PVOID AllocatedShellCode;
		DWORD ShellCodeSize;
		PVOID LocalAlloc;

		uintptr_t shell_data;
		HHOOK h_hook;

		nt_dll = LoadLibrary(XorStr("ntdll.dll"));
		AllocatedShellCode = Driver::AllocateProcessMem(ProcessID, 4096, PAGE_EXECUTE_READWRITE);
		ShellCodeSize = sizeof(RemoteDllMain) + sizeof(main_struct);
		LocalAlloc = VirtualAlloc(NULL, ShellCodeSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

		RtlCopyMemory(LocalAlloc, &RemoteDllMain, sizeof(RemoteDllMain));

		shell_data = (uintptr_t)AllocatedShellCode + sizeof(RemoteDllMain);
		*(uintptr_t*)((uintptr_t)LocalAlloc + shell_data_offset) = shell_data;
		main_struct* main_data = (main_struct*)((uintptr_t)LocalAlloc + sizeof(RemoteDllMain));
		main_data->dll_base = (HINSTANCE)dll_base;
		main_data->fn_dll_main = ((uintptr_t)dll_base + nt_header->OptionalHeader.AddressOfEntryPoint);

		Driver::WriteProcessMem(ProcessID, AllocatedShellCode, LocalAlloc, ShellCodeSize);
		h_hook = SetWindowsHookEx(WH_MOUSE, (HOOKPROC)AllocatedShellCode, nt_dll, TheadID);

		while (main_data->status != 2)
		{
			Driver::ReadProcessMem(ProcessID, (PVOID)shell_data, (PVOID)main_data, sizeof(main_struct));
			Sleep(10);
		}

		UnhookWindowsHookEx(h_hook);
		Driver::FreeProcessMem(ProcessID, AllocatedShellCode);
		VirtualFree(LocalAlloc, 0, MEM_RELEASE);
	}

	PVOID RVAVA(uintptr_t rva, PIMAGE_NT_HEADERS nt_head, PVOID local_image)
	{
		PIMAGE_SECTION_HEADER p_first_sect = IMAGE_FIRST_SECTION(nt_head);
		for (PIMAGE_SECTION_HEADER p_section = p_first_sect; p_section < p_first_sect + nt_head->FileHeader.NumberOfSections; p_section++)
			if (rva >= p_section->VirtualAddress && rva < p_section->VirtualAddress + p_section->Misc.VirtualSize)
				return (PUCHAR)local_image + p_section->PointerToRawData + (rva - p_section->VirtualAddress);

		return NULL;
	}

	uintptr_t ResolveFunctionAddress(LPCSTR modname, LPCSTR modfunc)
	{
		HMODULE hModule = LoadLibraryExA(modname, NULL, DONT_RESOLVE_DLL_REFERENCES);
		uintptr_t FunctionOffset = (uintptr_t)GetProcAddress(hModule, modfunc);
		FunctionOffset -= (uintptr_t)hModule;
		FreeLibrary(hModule);

		return FunctionOffset;
	}

	BOOL RelocateImage(PVOID p_remote_img, PVOID p_local_img, PIMAGE_NT_HEADERS nt_head)
	{
		struct reloc_entry
		{
			ULONG to_rva;
			ULONG size;
			struct
			{
				WORD offset : 12;
				WORD type : 4;
			} item[1];
		};

		uintptr_t delta_offset = (uintptr_t)p_remote_img - nt_head->OptionalHeader.ImageBase;
		if (!delta_offset) return true; else if (!(nt_head->OptionalHeader.DllCharacteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE)) return false;
		reloc_entry* reloc_ent = (reloc_entry*)RVAVA(nt_head->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress, nt_head, p_local_img);
		uintptr_t reloc_end = (uintptr_t)reloc_ent + nt_head->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size;

		if (reloc_ent == nullptr)
			return true;

		while ((uintptr_t)reloc_ent < reloc_end && reloc_ent->size)
		{
			DWORD records_count = (reloc_ent->size - 8) >> 1;
			for (DWORD i = 0; i < records_count; i++)
			{
				WORD fix_type = (reloc_ent->item[i].type);
				WORD shift_delta = (reloc_ent->item[i].offset) % 4096;

				if (fix_type == IMAGE_REL_BASED_ABSOLUTE)
					continue;

				if (fix_type == IMAGE_REL_BASED_HIGHLOW || fix_type == IMAGE_REL_BASED_DIR64)
				{
					uintptr_t fix_va = (uintptr_t)RVAVA(reloc_ent->to_rva, nt_head, p_local_img);

					if (!fix_va)
						fix_va = (uintptr_t)p_local_img;

					*(uintptr_t*)(fix_va + shift_delta) += delta_offset;
				}
			}

			reloc_ent = (reloc_entry*)((LPBYTE)reloc_ent + reloc_ent->size);
		} return true;
	}

	BOOL ResolveImport(HANDLE pid, DWORD thread_id, PVOID p_local_img, PIMAGE_NT_HEADERS nt_head)
	{
		PIMAGE_IMPORT_DESCRIPTOR import_desc = (PIMAGE_IMPORT_DESCRIPTOR)RVAVA(nt_head->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress, nt_head, p_local_img);
		if (!nt_head->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress || !nt_head->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size)
			return true;

		Logger::AddLogEntry(XorStr("Please Tab Into VRChat"), Logger::LogRaiser::Important);
		Sleep(250);

		LPSTR module_name = NULL;
		while ((module_name = (LPSTR)RVAVA(import_desc->Name, nt_head, p_local_img)))
		{
			uintptr_t base_image;
			base_image = CallRemoteLoadLibrary(pid, thread_id, module_name);

			if (!base_image)
				return false;

			PIMAGE_THUNK_DATA ih_data = (PIMAGE_THUNK_DATA)RVAVA(import_desc->FirstThunk, nt_head, p_local_img);
			while (ih_data->u1.AddressOfData)
			{
				if (ih_data->u1.Ordinal & IMAGE_ORDINAL_FLAG)
					ih_data->u1.Function = base_image + ResolveFunctionAddress(module_name, (LPCSTR)(ih_data->u1.Ordinal & 0xFFFF));
				else
				{
					IMAGE_IMPORT_BY_NAME* ibn = (PIMAGE_IMPORT_BY_NAME)RVAVA(ih_data->u1.AddressOfData, nt_head, p_local_img);
					ih_data->u1.Function = base_image + ResolveFunctionAddress(module_name, (LPCSTR)ibn->Name);
				} ih_data++;
			} import_desc++;
		}
		return true;
	}

	void WriteSections(HANDLE pid, PVOID p_module_base, PVOID local_image, PIMAGE_NT_HEADERS nt_head)
	{
		PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION(nt_head);
		for (WORD sec_cnt = 0; sec_cnt < nt_head->FileHeader.NumberOfSections; sec_cnt++, section++)
		{
			Driver::WriteProcessMem(pid, (PVOID)((uintptr_t)p_module_base + section->VirtualAddress), (PVOID)((uintptr_t)local_image + section->PointerToRawData), section->SizeOfRawData);
		}
	}

	void EraseDiscardableSect(HANDLE pid, PVOID p_module_base, PIMAGE_NT_HEADERS nt_head)
	{
		PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION(nt_head);
		for (WORD sec_cnt = 0; sec_cnt < nt_head->FileHeader.NumberOfSections; sec_cnt++, section++)
		{
			if (section->SizeOfRawData == 0)
				continue;

			if (section->Characteristics & IMAGE_SCN_MEM_DISCARDABLE)
			{
				PVOID zero_memory = VirtualAlloc(NULL, section->SizeOfRawData, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
				Driver::WriteProcessMem(pid, (PVOID)((uintptr_t)p_module_base + section->VirtualAddress), zero_memory, section->SizeOfRawData);
				VirtualFree(zero_memory, 0, MEM_RELEASE);
			}
		}
	}

	BOOL InjectDll(Injection_Info __IInfo)
	{
		PVOID DllImage;
		DWORD ProcessID, ThreadID = 0;
		PIMAGE_NT_HEADERS DllNtHeaders;

		
		if (__IInfo.FromVector)
			DllImage = GetDllByVector(reinterpret_cast<std::vector<uint32_t>&>(__IInfo.RawData));

		else if (__IInfo.FromPath)
			DllImage = GetDllByFile(__IInfo.Path);

		else
			return false;

		if (!DllImage)
			return false;

		DllNtHeaders = RtlImageNtHeader(DllImage);
		if (DllNtHeaders == INVALID_HANDLE_VALUE)
			return false;


		Logger::AddLogEntry(XorStr("Searching for VRChat Process 1/1"), Logger::LogRaiser::Info);
		Sleep(1000);
		ProcessID = GetVRChat(&ThreadID);

		if (ProcessID != 0 && ThreadID != 0)
		{
			Logger::AddLogEntry(XorStr("Found VRChat Process 1/1"), Logger::LogRaiser::Success);
			Sleep(1000);

			Logger::AddLogEntry(XorStr("Mapping Driver"), Logger::LogRaiser::Info);
			Sleep(600);

			if (!DrvMapper::MapDriver())
			{
				Logger::AddLogEntry(XorStr("Failed to Map Driver"), Logger::LogRaiser::Important);
				Sleep(1000);

				Logger::AddLogEntry(XorStr("Injection Failed"), Logger::LogRaiser::Error);
				return false;
			}
			else
			{
				Logger::AddLogEntry(XorStr("Successfully Mapped Driver"), Logger::LogRaiser::Success);
				Sleep(1000);
			}


			PVOID AllocateBase = Driver::AllocateProcessMem((HANDLE)ProcessID, DllNtHeaders->OptionalHeader.SizeOfImage, PAGE_EXECUTE_READWRITE);
			auto EndAdress = (uint64_t)((uint64_t)AllocateBase + DllNtHeaders->OptionalHeader.SizeOfImage);

			Logger::AddLogEntry(XorStr("Successfully Allocated Memory"), Logger::LogRaiser::Success);
			Sleep(750);

			if (!RelocateImage(AllocateBase, DllImage, DllNtHeaders))
			{
				Driver::FreeProcessMem((HANDLE)ProcessID, AllocateBase);
				return false;
			}

			Logger::AddLogEntry(XorStr("Successfully Allocated Image"), Logger::LogRaiser::Success);
			Sleep(1000);
			if (!ResolveImport((HANDLE)ProcessID, ThreadID, DllImage, DllNtHeaders))
			{
				Logger::AddLogEntry(XorStr("Injection Failed (Failed to Resolve Imports)"), Logger::LogRaiser::Error);
				Sleep(250);
				Driver::FreeProcessMem((HANDLE)ProcessID, AllocateBase);
				return false;
			}

			WriteSections((HANDLE)ProcessID, AllocateBase, DllImage, DllNtHeaders);
			Logger::AddLogEntry(XorStr("Successfully Wrote Sections"), Logger::LogRaiser::Success);
			Sleep(1000);

			Logger::AddLogEntry(XorStr("Calling Dll"));
			Sleep(750);
			CallDllMain((HANDLE)ProcessID, ThreadID, AllocateBase, DllNtHeaders, false);
			Logger::AddLogEntry(XorStr("Successfully Called Dll"), Logger::LogRaiser::Success);
			Sleep(1000);


			EraseDiscardableSect((HANDLE)ProcessID, AllocateBase, DllNtHeaders);
			Logger::AddLogEntry(XorStr("Successfully Cleaned Sections"), Logger::LogRaiser::Cleaner);
			Sleep(250);


			VirtualFree(DllImage, 0, MEM_RELEASE);
			Logger::AddLogEntry(XorStr("Successfully Freed Memory"), Logger::LogRaiser::Cleaner);
			Sleep(250);

			if (!DrvMapper::UnloadBeyondDriver())
			{
				Logger::AddLogEntry(XorStr("Failed to Unload Driver (You Might Get Banned!!!!)"), Logger::LogRaiser::Important);
				Sleep(250);
			}
			else
			{
				Logger::AddLogEntry(XorStr("Successfully Unloaded Driver"), Logger::LogRaiser::Cleaner);
				Sleep(1000);
			}

			Logger::AddLogEntry(XorStr("Injection Finished"), Logger::LogRaiser::Success);
			Sleep(1000);
		}
		else
		{
			Logger::AddLogEntry(XorStr("Please Open VRChat Before Trying to Inject"), Logger::LogRaiser::Info);
			Sleep(1000);
			Logger::AddLogEntry(XorStr("Injection Failed"), Logger::LogRaiser::Error);
			Sleep(1000);
		}
	}
}

