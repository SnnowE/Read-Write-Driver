#include <ntddk.h>

VOID DriverUnload(DRIVER_OBJECT* DriverObject) {

	UNREFERENCED_PARAMETER(DriverObject);
	DbgPrint("bye");
}

extern "C" NTSTATUS
DriverEntry(DRIVER_OBJECT* DriverObject, PUNICODE_STRING RegistryPath){

	UNREFERENCED_PARAMETER(RegistryPath);
	DbgPrint("Hello World");
	DriverObject->DriverUnload = DriverUnload;
	return STATUS_SUCCESS;
}

extern "C" NTSTATUS
Driver_Dispatch(PDEVICE_OBJECT DriverObject, PIRP Irp) {
	

}