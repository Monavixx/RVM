#include "OpDiv.h"
#include "../Core/FieldObject.h"

void OpDiv::Run()
{
	Value* firstData = frame->GetStack().pop();
	Value* secondData = frame->GetStack().pop();

	switch (firstData->valueType)
	{
	case ValueType::INT32:
		frame->GetStack().push(frame->AddValue(new Value(ValueType::INT32, UValue{.inum = firstData->value.inum / secondData->value.inum } )));
		break;

	case ValueType::FLOAT:
		frame->GetStack().push(frame->AddValue(new Value(ValueType::FLOAT, UValue{.fnum = firstData->value.fnum / secondData->value.fnum } )));
		break;

	default:
		Exit("div: data type is not a number");
	}
}

void OpDiv::Parse(ifstream& device)
{
}
