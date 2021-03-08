#include "OpMul.h"

void OpMul::Run()
{
	Object* firstData = frame->GetStack().pop();
	Object* secondData = frame->GetStack().pop();
	frame->GetStack().push(secondData->GetAddress());
	frame->GetStack().push(firstData->GetAddress());

	Class* declClass = GlobalVariables::classes[firstData->GetDataType()];
	if (declClass == nullptr)
		Exit("Mul: decl class not found");
	IMethod* operatorMul = declClass->GetMethod("operator*", { Parameter(secondData->GetDataType()) });
	if (operatorMul == nullptr)
		Exit("Mul: operator* not found");

	operatorMul->CallMethod(frame);
}

void OpMul::Parse(HANDLE& device)
{
}
