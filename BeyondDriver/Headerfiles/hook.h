#pragma once
#include "memory.h"

namespace Beyond
{
	BOOL CallKFunc(void* KFuncAddress);
	NTSTATUS hHandler(PVOID param);
}

enum Beyond_Instruction
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

typedef struct __BeyondInstruction
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
}BeyondInstruction_, * BeyondInstruction;

