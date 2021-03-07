#include "OpMul.h"

void OpMul::Run()
{
	Object* firstData = frame->GetStack().pop();
	Object* secondData = frame->GetStack().pop();
	frame->GetStack().push(secondData->GetAddress());
	frame->GetStack().push(firstData->GetAddress());

	StdClass* declClass = (*StdClassList::GetInstance())[firstData->GetDataType()];
	if (declClass == nullptr)
		Exit("Mul: decl class not found");
	StdMethod* operatorMul = declClass->GetMethod("operator*", { Parameter(secondData->GetDataType()) });
	if (operatorMul == nullptr)
		Exit("Mul: operator* not found");

	operatorMul->CallFunction(frame);
}

void OpMul::Parse(HANDLE& device)
{
}
