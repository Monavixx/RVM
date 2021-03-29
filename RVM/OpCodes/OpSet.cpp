#include "OpSet.h"
#include "../Core/FieldObject.h"
#include "../Libs/ConsoleTextStream.h"

void OpSet::Run()
{
	Value* data = frame->GetStack().pop();
	Variable* variable = frame->GetVariable(id);
	if (variable == nullptr)
		Exit("set: local variable with id " + std::to_string(id) + " not exists");

	if (data == nullptr)
	{
		variable->SetValue(nullptr);
		return;
	}

	String dataType = Value::GetDataType(data);
	if (dataType != variable->GetDataType() && dataType != "Relax.Null")
		Exit("set: data types do not match");

	Value* oldData = variable->GetValue();
	if(oldData == nullptr)
		variable->SetValue(data);
	else
	{
		oldData->value = data->value;
		oldData->valueType = data->valueType;
	}
}

void OpSet::Parse(ifstream& device)
{
	id = ByteArrayRead::ReadInt(device);
}
