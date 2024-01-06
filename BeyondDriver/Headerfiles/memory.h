#pragma once
#include "definitions.h"

namespace Utils {
	PVOID GetSystemModuleBase(const char* module_name);
	PVOID GetSystemModuleExport(const char* module_name, LPCSTR routing_name);
	PVOID GetProcessHandle(HANDLE pid);
}

namespace Memory {
	BOOL WriteMemory(void* address, void* buffer, size_t size);
	BOOL WriteReadOnlyMemory(void* address, void* buffer, size_t size);
	BOOL WriteProcessMemory(HANDLE pid, PVOID address, PVOID buffer, DWORD size);
	BOOL ReadProcessMemory(HANDLE pid, PVOID address, PVOID buffer, DWORD size);
	PVOID AllocateVirtualMemory(HANDLE pid, ULONGLONG size, DWORD protect);
	VOID FreeVirtualMemory(HANDLE pid, PVOID base);
	BOOL ProtectVirtualMemory(HANDLE pid, UINT_PTR base, ULONGLONG size, DWORD protection);
	BOOL WriteProcessMemory64(HANDLE pid, PVOID64 address, PVOID64 buffer, DWORD size);
	BOOL ReadProcessMemory64(HANDLE pid, PVOID64 address, PVOID64 buffer, DWORD size);
}