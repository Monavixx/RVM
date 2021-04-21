#include "OpMul.h"
#include "../Core/FieldObject.h"

void OpMul::Run()
{
	Value* firstData = frame->GetStack().pop();
	Value* secondData = frame->GetStack().pop();

	switch (firstData->valueType)
	{
	case ValueType::INT32:
		frame->GetStack().push(frame->AddValue(new Value(ValueType::INT32, UValue(get<int>(firstData->value) * get<int>(secondData->value)))));
		break;

	case ValueType::FLOAT:
		frame->GetStack().push(frame->AddValue(new Value(ValueType::FLOAT, UValue(get<float>(firstData->value) * get<float>(secondData->value)))));
		break;

	default:
		Exit("mul: data type not supported", 27);
	}
}

void OpMul::Parse(ifstream& device)
{
}
