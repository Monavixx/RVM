#include "OpDiv.h"

void OpDiv::Run()
{
	Object* firstData = frame->GetStack().pop();
	Object* secondData = frame->GetStack().pop();
	frame->GetStack().push(secondData);
	frame->GetStack().push(firstData);

	StdClass* declClass = (*StdClassList::GetInstance())[firstData->GetDataType()];
	if (declClass == nullptr)
		Exit("Div: decl class not found");
	StdMethod* operatorDiv = declClass->GetMethod("operator/", { Parameter(secondData->GetDataType()) });
	if (operatorDiv == nullptr)
		Exit("Div: operator/ not found");

	operatorDiv->CallFunction(gv, frame);
}

void OpDiv::Parse(QIODevice& device)
{
}
