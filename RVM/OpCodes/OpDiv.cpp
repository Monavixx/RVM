#include "OpDiv.h"

void OpDiv::Run()
{
	Object* firstData = frame->GetStack().pop();
	Object* secondData = frame->GetStack().pop();
	frame->GetStack().push(secondData->GetAddress());
	frame->GetStack().push(firstData->GetAddress());

	Class* declClass = GlobalVariables::classes[firstData->GetDataType()];
	if (declClass == nullptr)
		Exit("Div: decl class not found");
	IMethod* operatorDiv = declClass->GetMethod("operator/", { Parameter(secondData->GetDataType()) });
	if (operatorDiv == nullptr)
		Exit("Div: operator/ not found");

	operatorDiv->CallMethod(frame);
}

void OpDiv::Parse(HANDLE& device)
{
}
