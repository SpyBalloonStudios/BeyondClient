#include <Windows.h>

enum Moz_Instructions
{
    WRITE_KERNEL_MEMORY,
    WRITE_PROCESS_MEMORY,
    READ_KERNEL_MEMORY,
    READ_PROCESS_MEMORY,
    ALLOCATE_MEMORY,
    FREE_MEMORY,
    PROTECT_MEMORY,
    ATTACH_PROCESS,
    OPEN_PROCESS,
    READ_PROCESS_MEMORY64,
    WRITE_PROCESS_MEMORY64
};

typedef struct __MozInstruction
{
    ULONG instruction;
    void* buffer_address;
    UINT_PTR address;
    ULONGLONG size;
    ULONG pid;
    BOOLEAN read;
    BOOLEAN req_base;
    void* output;
    const char* module_name;
    PVOID allocate_base;
    DWORD protect;
    PVOID64 address64;
    PVOID64 buffer_address64;
}MozInstruction_, * MozInstruction;

namespace Driver
{
    BOOL SendInstruction(MozInstruction __Instruction);
    BOOL ReadProcessMem(HANDLE pid, PVOID address, PVOID buffer, DWORD size);
    BOOL ReadProcessMem64(HANDLE pid, PVOID64 address64, PVOID64 buffer64, DWORD size);
    BOOL WriteProcessMem(HANDLE pid, PVOID address, PVOID buffer, DWORD size);
    BOOL WriteProcessMem64(HANDLE pid, PVOID64 address64, PVOID64 buffer64, DWORD size);
    PVOID AllocateProcessMem(HANDLE pid, ULONGLONG size, DWORD protect);
    BOOL FreeProcessMem(HANDLE pid, PVOID base);
    BOOL ProtectMem(HANDLE pid, UINT_PTR base, ULONGLONG size, DWORD protection);
    PVOID OpenProcess(HANDLE pid);
}

