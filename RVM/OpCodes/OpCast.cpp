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
			frame->GetStack().push(frame->AddValue(new Value(Value::GetValueType(dataType), UValue{ .fnum = static_cast<float>(data->value.inum) })));
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
			frame->GetStack().push(frame->AddValue(new Value(Value::GetValueType(dataType), UValue{ .inum = static_cast<int>(data->value.fnum) })));
			break;
		}
		}
		break;
	}
	}
}

void OpCast::Parse(HANDLE& device)
{
	dataType = ByteArrayRead::ReadSizeAndString(device);
	newValueType = Value::GetValueType(dataType);
}
