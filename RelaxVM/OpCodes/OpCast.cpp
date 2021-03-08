#include "OpCast.h"

void OpCast::Run()
{
	Object* data = frame->GetStack().top();
	
	IMethod* methodCast = declClass->GetMethod("cast", { Parameter(data->GetDataType()) });
	if (methodCast == nullptr)
		Exit("cast: method cast not found");

	methodCast->CallMethod(frame);
}

void OpCast::Parse(HANDLE& device)
{
	dataType = ByteArrayRead::ReadSizeAndString(device);
	
	declClass = GlobalVariables::classes[dataType];
	if (declClass == nullptr)
		Exit("cast: decl class not found");
}
