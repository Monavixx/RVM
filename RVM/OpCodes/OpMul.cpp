#include "OpMul.h"
#include "../Core/FieldObject.h"

void OpMul::Run()
{
	Value* firstData = frame->GetStack().pop();
	Value* secondData = frame->GetStack().pop();

	switch (firstData->valueType)
	{
	case ValueType::INT32:
		frame->GetStack().push(frame->AddValue(new Value(ValueType::INT32, UValue{.inum = firstData->value.inum * secondData->value.inum } )));
		break;

	case ValueType::FLOAT:
		frame->GetStack().push(frame->AddValue(new Value(ValueType::FLOAT, UValue{.fnum = firstData->value.fnum * secondData->value.fnum } )));
		break;

	default:
		Exit("mul: data type is not a number");
	}
}

void OpMul::Parse(ifstream& device)
{
}
