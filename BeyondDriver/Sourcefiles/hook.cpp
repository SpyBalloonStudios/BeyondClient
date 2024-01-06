#include "..\Headerfiles\hook.h"
#include "..\Headerfiles\Globals.h"

BOOL Beyond::CallKFunc(void* KFuncAddress)
{
	if (!KFuncAddress)
		return FALSE;

	PVOID* function = reinterpret_cast<PVOID*>(Utils::GetSystemModuleExport(Globals::Hook::ModuleName, Globals::Hook::RoutingName));
	if (!function)
		return FALSE;

	BYTE orig[] = { 0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,0x00 ,0x00 ,0x00 ,0x00 }; 
	BYTE shellcode[] = { 0x48,0xB8 };// mov rax,xxx
	BYTE shellcode_end[] = {0xFF,0xE0};// jmp rax

	RtlSecureZeroMemory(&orig,sizeof(orig));
	memcpy((PVOID)(ULONG_PTR)orig,&shellcode,sizeof(shellcode));
	uintptr_t hook_address = reinterpret_cast<uintptr_t>(KFuncAddress);
	memcpy((PVOID)((ULONG_PTR)orig+sizeof(shellcode)),&hook_address,sizeof(void*)); 
	memcpy((PVOID)((ULONG_PTR)orig + sizeof(shellcode) + sizeof(void*)), &shellcode_end, sizeof(shellcode_end));
	Memory::WriteReadOnlyMemory(function,&orig,sizeof(orig));
	return TRUE;
}

NTSTATUS Beyond::hHandler(PVOID param)
{
	if (!MmIsAddressValid(param))
	{
		return STATUS_SUCCESS;
	}

	BeyondInstruction pParam = (BeyondInstruction)param;
	switch (pParam->instruction)
	{
		case READ_PROCESS_MEMORY:
			Memory::ReadProcessMemory((HANDLE)pParam->pid,(PVOID)pParam->address,pParam->buffer_address,pParam->size);
			break;
		case WRITE_PROCESS_MEMORY:
			Memory::WriteProcessMemory((HANDLE)pParam->pid, (PVOID)pParam->address, pParam->buffer_address, pParam->size);
			break;
		case ALLOCATE_MEMORY:
			pParam->allocate_base = Memory::AllocateVirtualMemory((HANDLE)pParam->pid,pParam->size,pParam->protect);
			break;
		case FREE_MEMORY:
			Memory::FreeVirtualMemory((HANDLE)pParam->pid,pParam->allocate_base);
			break;
		case PROTECT_MEMORY:
			Memory::ProtectVirtualMemory((HANDLE)pParam->pid,pParam->address,pParam->size,pParam->protect);
			break;
		case OPEN_PROCESS:
			pParam->buffer_address = Utils::GetProcessHandle((HANDLE)pParam->pid);
			break;
		case WRITE_PROCESS_MEMORY64:
			Memory::WriteProcessMemory64((HANDLE)pParam->pid, (PVOID)pParam->address64, pParam->buffer_address64, pParam->size);
			break;
		case READ_PROCESS_MEMORY64:
			Memory::ReadProcessMemory64((HANDLE)pParam->pid, (PVOID)pParam->address64, pParam->buffer_address64, pParam->size);
			break;

		default:
			break;
	}
	return STATUS_SUCCESS;
}
