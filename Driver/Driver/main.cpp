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
	
	DriverObject->MajorFunction[IRP_MJ_CREATE] = BoosterCreateClose;
	DriverObject->MajorFunction[IRP_MJ_CLOSE] = BoosterCreateClose;
	
	DriverObject->MajorFunction[IRP_MJ_WRITE] = BoosterWrite;

	return STATUS_SUCCESS;
}

NTSTATUS BoosterCreateClose(PDEVICE_OBJECT DriverObject, PIRP Irp) {
	

}

NTSTATUS BoosterWrite(PDEVICE_OBJECT DeviceObject, PIRP Irp) {


}