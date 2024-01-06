#include "..\BeyondDriver\Headerfiles\driver.h"
#include "..\BeyondDriver\Headerfiles\hook.h"
#include "..\BeyondDriver\Headerfiles\cleaner.h"
#include <ntddk.h>

VOID MyThread()
{
    PsTerminateSystemThread(STATUS_SUCCESS);
}

NTSTATUS ActualEntry(PDRIVER_OBJECT  DriverObject, PUNICODE_STRING RegistryPath)
{
    UNREFERENCED_PARAMETER(DriverObject);
    UNREFERENCED_PARAMETER(RegistryPath);

    clean_piddbcachetalbe();
    BOOL status = Beyond::CallKFunc(&Beyond::hHandler);
    return STATUS_SUCCESS;
}

NTSTATUS DriverEntry(PDRIVER_OBJECT  DriverObject, PUNICODE_STRING RegistryPath)
{
    UNREFERENCED_PARAMETER(DriverObject);
    UNREFERENCED_PARAMETER(RegistryPath);

    return STATUS_SUCCESS;
}