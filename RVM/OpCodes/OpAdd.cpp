#include "OpAdd.h"
#include "../Core/FieldObject.h"

void OpAdd::Run()
{
	Value* firstData = frame->GetStack().pop();
	Value* secondData = frame->GetStack().pop();

	switch (firstData->valueType)
	{
	case ValueType::INT32:
		frame->GetStack().push(frame->AddValue(new Value(ValueType::INT32, UValue(get<int>(firstData->value) + get<int>(secondData->value)))));
		break;

	case ValueType::FLOAT:
		frame->GetStack().push(frame->AddValue(new Value(ValueType::FLOAT, UValue(get<float>(firstData->value) + get<float>(secondData->value)))));
		break;

	default:
		Exit("add: data type is not a number");
	}
	
}

void OpAdd::Parse(ifstream& device)
{
}
