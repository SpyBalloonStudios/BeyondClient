#include "..\Headerfiles\memory.h"

namespace Memory {

	BOOL Memory::WriteMemory(void* address, void* buffer, size_t size)
	{
		if (!RtlCopyMemory(address, buffer, size))
		{
			return FALSE;
		}
		else
		{
			return TRUE;
		}
	}

	BOOL Memory::WriteReadOnlyMemory(void* address, void* buffer, size_t size)
	{
		PMDL Mdl = IoAllocateMdl(address, size, FALSE, FALSE, NULL);
		if (!Mdl)
			return false;
		MmProbeAndLockPages(Mdl, KernelMode, IoReadAccess);
		PVOID Mapping = MmMapLockedPagesSpecifyCache(Mdl, KernelMode, MmNonCached, NULL, FALSE, NormalPagePriority);
		MmProtectMdlSystemAddress(Mdl, PAGE_READWRITE);
		WriteMemory(Mapping, buffer, size);
		MmUnmapLockedPages(Mapping, Mdl);
		MmUnlockPages(Mdl);
		IoFreeMdl(Mdl);

		return TRUE;
	}


	BOOL Memory::WriteProcessMemory(HANDLE pid, PVOID address, PVOID buffer, DWORD size)
	{
		PEPROCESS process = NULL;
		NTSTATUS status;
		SIZE_T real_size;

		status = PsLookupProcessByProcessId((HANDLE)pid, &process);
		if (process == NULL || status != STATUS_SUCCESS)
		{
			return FALSE;
		}

		status = MmCopyVirtualMemory(PsGetCurrentProcess(), buffer, process, address, size, KernelMode, &real_size);

		ObDereferenceObject(process);
		return TRUE;
	}
	BOOL Memory::WriteProcessMemory64(HANDLE pid, PVOID64 address, PVOID64 buffer, DWORD size)
	{
		PEPROCESS process = NULL;
		NTSTATUS status = PsLookupProcessByProcessId((HANDLE)pid, &process);
		SIZE_T real_size;
		if (process == NULL || status != STATUS_SUCCESS)
		{
			return FALSE;
		}

		status = MmCopyVirtualMemory(PsGetCurrentProcess(), buffer, process, address, size, KernelMode, &real_size);


		ObDereferenceObject(process);
		return TRUE;
	}
	BOOL Memory::ReadProcessMemory(HANDLE pid, PVOID address, PVOID buffer, DWORD size)
	{
		PEPROCESS process = NULL;
		NTSTATUS status = PsLookupProcessByProcessId((HANDLE)pid, &process);
		SIZE_T real_size;

		if (process == NULL || status != STATUS_SUCCESS)
		{
			return FALSE;
		}

		status = MmCopyVirtualMemory(process, address, PsGetCurrentProcess(), buffer, size, KernelMode, &real_size);

		ObDereferenceObject(process);
		return TRUE;

	}
	BOOL Memory::ReadProcessMemory64(HANDLE pid, PVOID64 address, PVOID64 buffer, DWORD size)
	{
		PEPROCESS process = NULL;
		NTSTATUS status = PsLookupProcessByProcessId((HANDLE)pid, &process);
		SIZE_T real_size;

		if (process == NULL || status != STATUS_SUCCESS)
		{
			return FALSE;
		}

		status = MmCopyVirtualMemory(process, address, PsGetCurrentProcess(), buffer, size, KernelMode, &real_size);

		ObDereferenceObject(process);
		return TRUE;

	}
	PVOID Memory::AllocateVirtualMemory(HANDLE pid, ULONGLONG size, DWORD protect)
	{
		PEPROCESS process = NULL;
		NTSTATUS status;
		PVOID base_address = NULL;
		KAPC_STATE apc;
		size_t real_size = size;

		status = PsLookupProcessByProcessId((HANDLE)pid, &process);
		if (process == NULL || status != STATUS_SUCCESS)
		{
			return NULL;
		}

		KeStackAttachProcess(process, &apc);
		status = ZwAllocateVirtualMemory(ZwCurrentProcess(), &base_address, 0, &real_size, MEM_COMMIT, protect);

		KeUnstackDetachProcess(&apc);
		ObDereferenceObject(process);
		return base_address;
	}

	VOID Memory::FreeVirtualMemory(HANDLE pid, PVOID base)
	{
		PEPROCESS process = NULL;
		SIZE_T region_size;
		NTSTATUS status;
		PVOID base_address;
		KAPC_STATE apc;


		status = PsLookupProcessByProcessId((HANDLE)pid, &process);
		if (process == NULL || status != STATUS_SUCCESS)
		{
			return;
		}

		KeStackAttachProcess(process, &apc);
		region_size = 0;
		base_address = base;

		status = ZwFreeVirtualMemory(ZwCurrentProcess(), &base_address, &region_size, MEM_RELEASE);

		KeUnstackDetachProcess(&apc);
		ObDereferenceObject(process);
		return;
	}

	BOOL Memory::ProtectVirtualMemory(HANDLE pid, UINT_PTR base, ULONGLONG size, DWORD protection)
	{
		PEPROCESS process = NULL;
		NTSTATUS status;
		KAPC_STATE apc;
		PVOID base_address;
		SIZE_T protect_size;
		ULONG old_protect;

		status = PsLookupProcessByProcessId((HANDLE)pid, &process);
		if (process == NULL || status != STATUS_SUCCESS)
		{
			return NULL;
		}

		base_address = (PVOID)base;
		protect_size = size;

		KeStackAttachProcess(process, &apc);
		status = ZwProtectVirtualMemory(ZwCurrentProcess(), &base_address, &protect_size, protection, &old_protect);
		KeUnstackDetachProcess(&apc);
		ObDereferenceObject(process);
		return TRUE;
	}

}
namespace Utils {
	PVOID Utils::GetProcessHandle(HANDLE pid)
	{
		PEPROCESS process = NULL;
		NTSTATUS status;
		UNICODE_STRING Unicode;
		PVOID hProcess = NULL;

		status = PsLookupProcessByProcessId((HANDLE)pid, &process);
		if (process == NULL || status != STATUS_SUCCESS)
		{
			return NULL;
		}

		status = ObOpenObjectByPointer(
			process,
			0,
			NULL,
			PROCESS_ALL_ACCESS,
			*PsProcessType,
			KernelMode,
			&hProcess
		);

		ObDereferenceObject(process);
		return hProcess;
	}

	PVOID Utils::GetSystemModuleBase(const char* module_name)
	{
		ULONG bytes = 0;
		NTSTATUS status = ZwQuerySystemInformation(SystemModuleInformation, NULL, bytes, &bytes);
		if (!bytes)
			return NULL;
		PRTL_PROCESS_MODULES modules = (PRTL_PROCESS_MODULES)ExAllocatePoolWithTag(NonPagedPool, bytes, 0x4e554c4c);//"NULL"
		status = ZwQuerySystemInformation(SystemModuleInformation, modules, bytes, &bytes);
		if (!NT_SUCCESS(status))
			return NULL;
		PRTL_PROCESS_MODULE_INFORMATION Module = modules->Modules;
		PVOID module_base = 0, module_size = 0;
		for (ULONG i = 0; i < modules->NumberOfModules; i++)
		{


			if (strcmp(Module[i].FullPathName, module_name) == 0)
			{
				module_base = Module[i].ImageBase;
				module_size = (PVOID)Module[i].ImageBase;
				break;
			}
		}
		if (modules)
			ExFreePoolWithTag(modules, NULL);
		if (module_base <= NULL)
			return NULL;
		return module_base;
	}

	PVOID Utils::GetSystemModuleExport(const char* module_name, LPCSTR routing_name)
	{
		PVOID lpModule = GetSystemModuleBase(module_name);

		if (!lpModule)
			return NULL;

		return RtlFindExportedRoutineByName(lpModule, routing_name);
	}
}