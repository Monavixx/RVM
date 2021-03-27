#include "OpSetfield.h"
#include "../Core/FieldObject.h"

void OpSetfield::Run()
{
	Object* target = frame->GetStack().pop()->value.object;
	Value* value = frame->GetStack().pop();
	if (target->GetField(name).field->GetDataType() != Value::GetDataType(value))
		Exit("setfield: data types do not match");
	if(value->valueType == ValueType::OBJECT)
		value->value.object->IncAmountUsers();
	target->SetField(name, value);
}

void OpSetfield::Parse(HANDLE& device)
{
	name = ByteArrayRead::ReadSizeAndString(device);
}
