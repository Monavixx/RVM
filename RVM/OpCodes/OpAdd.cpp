#include "OpAdd.h"

void OpAdd::Run()
{
	Object* firstData = frame->GetStack().pop();
	Object* secondData = frame->GetStack().pop();
	frame->GetStack().push(secondData->GetAddress());
	frame->GetStack().push(firstData->GetAddress());

	Class* declClass = GlobalVariables::classes[firstData->GetDataType()];
	if (declClass == nullptr)
		Exit("Add: decl class not found");
	IMethod* operatorAdd = declClass->GetMethod("operator+", { Parameter(secondData->GetDataType()) });
	if (operatorAdd == nullptr)
		Exit("Add: operator+ not found");

	operatorAdd->CallMethod(frame);
}

void OpAdd::Parse(HANDLE& device)
{
}
