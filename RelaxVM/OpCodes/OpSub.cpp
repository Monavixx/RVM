#include "OpSub.h"

void OpSub::Run()
{
	Object* firstData = frame->GetStack().pop();
	Object* secondData = frame->GetStack().pop();
	frame->GetStack().push(secondData);
	frame->GetStack().push(firstData);

	StdClass* declClass = (*StdClassList::GetInstance())[firstData->GetDataType()];
	if (declClass == nullptr)
		Exit("Sub: decl class not found");
	StdMethod* operatorSub = declClass->GetMethod("operator-", { Parameter(secondData->GetDataType()) });
	if (operatorSub == nullptr)
		Exit("Sub: operator- not found");

	operatorSub->CallFunction(frame);
}

void OpSub::Parse(QIODevice& device)
{
}
