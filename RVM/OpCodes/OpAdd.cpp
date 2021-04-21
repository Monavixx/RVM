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

	case ValueType::STR:
		frame->GetStack().push(frame->AddValue(new Value(ValueType::STR, UValue(get<String>(firstData->value) + get<String>(secondData->value)))));
		break;

	default:
		Exit("add: data type not supported. Data type: "_ss + Value::GetDataType(firstData), 5);
	}
	
}

void OpAdd::Parse(ifstream& device)
{
}
