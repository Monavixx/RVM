#include "OpSub.h"

void OpSub::Run()
{
	Object* firstData = frame->GetStack().pop();
	Object* secondData = frame->GetStack().pop();
	frame->GetStack().push(secondData);
	frame->GetStack().push(firstData);

	StdClass* declClass = StdClassList::GetInstance()->FindClassByName(firstData->GetDataType());
	if (declClass == nullptr)
		Exit("Add: decl class not found");
	StdMethod* operatorAdd = declClass->GetMethod("operator-", { Parameter(secondData->GetDataType()) });
	if (operatorAdd == nullptr)
		Exit("Add: operator- not found");

	Object* returnedObject = operatorAdd->CallFunction(frame->GetStack());
	if (returnedObject != nullptr)
	{
		gv->heap.push_back(returnedObject);
		frame->GetStack().push(returnedObject);
	}
}

void OpSub::Parse(QIODevice& device)
{
}
