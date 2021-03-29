#include "OpSetfield.h"
#include "../Core/FieldObject.h"

void OpSetfield::Run()
{
	Object* target = get<Object*>(frame->GetStack().pop()->value);
	Value* value = frame->GetStack().pop();
	if (target->GetField(name)->field->GetDataType() != Value::GetDataType(value))
		Exit("setfield: data types do not match");
	if(value->valueType == ValueType::OBJECT)
		get<Object*>(value->value)->IncAmountUsers();
	target->SetField(name, value);
}

void OpSetfield::Parse(ifstream& device)
{
	name = ByteArrayRead::ReadSizeAndString(device);
}
