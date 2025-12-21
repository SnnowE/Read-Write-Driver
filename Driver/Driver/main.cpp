#include <ntddk.h>

PDEVICE_OBJECT DeviceObject;

VOID DriverUnload(DRIVER_OBJECT* DriverObject) {

	UNREFERENCED_PARAMETER(DriverObject);
	DbgPrint("bye");
}

void BoosterUnload(_In_ PDRIVER_OBJECT DriverObject) {
	UNICODE_STRING symLink = RTL_CONSTANT_STRING(L"\\??\\Booster");
	IoDeleteSymbolicLink(&symLink);

	IoDeleteDevice(DriverObject->DeviceObject);
}

NTSTATUS BoosterCreateClose(PDEVICE_OBJECT DriverObject, PIRP Irp) {

}

NTSTATUS BoosterWrite(PDEVICE_OBJECT DeviceObject, PIRP Irp) {

}

extern "C" NTSTATUS
DriverEntry(DRIVER_OBJECT* DriverObject, PUNICODE_STRING RegistryPath){

	UNREFERENCED_PARAMETER(RegistryPath);
	DbgPrint("Hello World");
	DriverObject->DriverUnload = DriverUnload;
	
	DriverObject->MajorFunction[IRP_MJ_CREATE] = BoosterCreateClose;
	DriverObject->MajorFunction[IRP_MJ_CLOSE] = BoosterCreateClose;
	DriverObject->MajorFunction[IRP_MJ_WRITE] = BoosterWrite;

	UNICODE_STRING devName = RTL_CONSTANT_STRING(L"\\Device\\Booster");
	NTSTATUS status = IoCreateDevice(DriverObject, 0, &devName, FILE_DEVICE_UNKNOWN, 0, FALSE, &DeviceObject);
	if (!NT_SUCCESS(status)) {
		KdPrint(("Failed to create divice object *ox%o8X)\n", status));
		return status;
	}
	return STATUS_SUCCESS;
}



