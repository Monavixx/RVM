#include "OpSet.h"
#include "../Core/FieldObject.h"
#include "../Libs/ConsoleTextStream.h"

void OpSet::Run()
{
	Value* data = frame->GetStack().pop();
	Variable* variable = frame->GetVariable(id);
	if (variable == nullptr)
		Exit("set: local variable with id " + std::to_string(id) + " not exists");

	String dataType = Value::GetDataType(data);
	if (dataType != variable->GetDataType() && dataType != "Relax.Null")
		Exit("set: data types do not match");

	Value* oldData = variable->GetValue();
	if(oldData != nullptr && oldData->valueType == ValueType::OBJECT) oldData->value.object->DecAmountUsers();

	if (oldData != nullptr && data->valueType == ValueType::OBJECT) data->value.object->IncAmountUsers();
	variable->SetValue(data);
}

void OpSet::Parse(HANDLE& device)
{
	id = ByteArrayRead::ReadInt(device);
}
