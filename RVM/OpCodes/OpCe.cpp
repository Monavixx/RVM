#include "OpCe.h"
#include "../Core/FieldObject.h"

void OpCe::Run()
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

	case ValueType::BOOL:
		frame->GetStack().push(frame->AddValue(new Value(ValueType::BOOL, UValue(get<bool>(firstData->value) == get<bool>(secondData->value)))));
		break;

	case ValueType::STR:
		frame->GetStack().push(frame->AddValue(new Value(ValueType::BOOL, UValue(get<String>(firstData->value) == get<String>(secondData->value)))));
		break;

	default:
		Exit("ce: data type not supported");
	}
}

void OpCe::Parse(ifstream& device)
{
}
