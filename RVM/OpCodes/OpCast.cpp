#include "OpCast.h"
#include "../Core/FieldObject.h"

void OpCast::Run()
{
	Value* data = frame->GetStack().pop();
	
	switch (newValueType)
	{
	case ValueType::FLOAT:
	{
		switch (data->valueType)
		{
		case ValueType::INT32:
		{
			frame->GetStack().push(frame->AddValue(new Value(Value::GetValueType(dataType), UValue(static_cast<float>(get<int>(data->value))))));
			break;
		}
		}
		break;
	}
	
	case ValueType::INT32:
	{
		switch (data->valueType)
		{
		case ValueType::FLOAT:
		{
			frame->GetStack().push(frame->AddValue(new Value(Value::GetValueType(dataType), UValue(static_cast<int>(get<float>(data->value))))));
			break;
		}
		}
		break;
	}
	}
}

void OpCast::Parse(ifstream& device)
{
	dataType = ByteArrayRead::ReadSizeAndString(device);
	newValueType = Value::GetValueType(dataType);
}
