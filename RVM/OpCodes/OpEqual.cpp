#include "OpEqual.h"
#include "../Core/FieldObject.h"

void OpEqual::Run()
{
	Value* firstData = frame->GetStack().pop();
	Value* secondData = frame->GetStack().pop();

	switch (firstData->valueType)
	{
	case ValueType::INT32:
		frame->GetStack().push(frame->AddValue(new Value(ValueType::BOOL, UValue(get<int>(firstData->value) == get<int>(secondData->value)))));
		break;

	case ValueType::FLOAT:
		frame->GetStack().push(frame->AddValue(new Value(ValueType::BOOL, UValue(get<float>(firstData->value) == get<float>(secondData->value)))));
		break;

	default:
		Exit("equal: data type is not a number");
	}
}

void OpEqual::Parse(ifstream& device)
{
}
