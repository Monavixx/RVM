#include "OpSub.h"

void OpSub::Run()
{
	Object* firstData = frame->GetStack().pop();
	Object* secondData = frame->GetStack().pop();
	frame->GetStack().push(secondData->GetAddress());
	frame->GetStack().push(firstData->GetAddress());

	Class* declClass = GlobalVariables::classes[firstData->GetDataType()];
	if (declClass == nullptr)
		Exit("Sub: decl class not found");
	IMethod* operatorSub = declClass->GetMethod("operator-", { Parameter(secondData->GetDataType()) });
	if (operatorSub == nullptr)
		Exit("Sub: operator- not found");

	operatorSub->CallMethod(frame);
}

void OpSub::Parse(HANDLE& device)
{
}
