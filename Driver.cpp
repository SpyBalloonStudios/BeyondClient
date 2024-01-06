#include "Imports.h"
#include "Globals.h"
#include "Driver.h"
#include "XorStr.h"

namespace Driver
{
    BOOL Driver::SendInstruction(MozInstruction __Instruction)
    {
        void* hooked_function = GetProcAddress(LoadLibrary(XorStr("win32u.dll")), Globals::Get()->RoutingName);
        if (hooked_function == NULL)
            return FALSE;

        auto func = static_cast<uint64_t(_stdcall*)(MozInstruction)>(hooked_function);
        func(__Instruction);
        return TRUE;
    }

    BOOL Driver::ReadProcessMem(HANDLE pid, PVOID address, PVOID buffer, DWORD size)
    {
        MozInstruction_ msg;
        msg.instruction = READ_PROCESS_MEMORY;
        msg.pid = (ULONG)pid;
        msg.address = (UINT_PTR)address;
        msg.buffer_address = buffer;
        msg.size = size;
        return SendInstruction(&msg);
    }

    BOOL Driver::ReadProcessMem64(HANDLE pid, PVOID64 address64, PVOID64 buffer64, DWORD size)
    {
        MozInstruction_ msg;
        msg.instruction = READ_PROCESS_MEMORY64;
        msg.pid = (ULONG)pid;
        msg.address64 = address64;
        msg.buffer_address64 = buffer64;
        msg.size = size;
        return SendInstruction(&msg);

    }
    BOOL Driver::WriteProcessMem(HANDLE pid, PVOID address, PVOID buffer, DWORD size)
    {
        MozInstruction_ msg;
        msg.instruction = WRITE_PROCESS_MEMORY;
        msg.pid = (ULONG)pid;
        msg.address = (UINT_PTR)address;
        msg.buffer_address = buffer;
        msg.size = size;
        return SendInstruction(&msg);
    }

    BOOL Driver::WriteProcessMem64(HANDLE pid, PVOID64 address64, PVOID64 buffer64, DWORD size)
    {
        MozInstruction_ msg;
        msg.instruction = WRITE_PROCESS_MEMORY64;
        msg.pid = (ULONG)pid;
        msg.address64 = address64;
        msg.buffer_address64 = buffer64;
        msg.size = size;
        return SendInstruction(&msg);
    }

    PVOID Driver::AllocateProcessMem(HANDLE pid, ULONGLONG size, DWORD protect)
    {
        MozInstruction_ msg;
        msg.instruction = ALLOCATE_MEMORY;
        msg.pid = (ULONG)pid;
        msg.address = NULL;
        msg.buffer_address = NULL;
        msg.size = size;
        msg.protect = protect;
        SendInstruction(&msg);
        return msg.allocate_base;
    }

    BOOL Driver::FreeProcessMem(HANDLE pid, PVOID base)
    {
        MozInstruction_ msg;
        msg.instruction = FREE_MEMORY;
        msg.pid = (ULONG)pid;
        msg.address = (UINT_PTR)base;
        msg.buffer_address = NULL;
        return SendInstruction(&msg);
    }

    BOOL Driver::ProtectMem(HANDLE pid, UINT_PTR base, ULONGLONG size, DWORD protection)
    {
        MozInstruction_ msg;
        msg.instruction = PROTECT_MEMORY;
        msg.pid = (ULONG)pid;
        msg.address = (UINT_PTR)base;
        msg.buffer_address = NULL;
        msg.size = size;
        msg.protect = protection;
        return SendInstruction(&msg);
    }

    PVOID Driver::OpenProcess(HANDLE pid)
    {
        MozInstruction_ msg;
        msg.instruction = OPEN_PROCESS;
        msg.pid = (ULONG)pid;
        msg.address = NULL;
        msg.buffer_address = NULL;
        msg.size = 0;
        msg.protect = NULL;
        SendInstruction(&msg);
        return msg.buffer_address;
    }
}