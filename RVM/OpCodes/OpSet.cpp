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

	Value* oldData = variable->GetValue();
	if (data->valueType == ValueType::OBJECT)
		GlobalVariables::heap[get<size_t>(data->value)]->IncAmountUsers();
	variable->SetValue(data);
}

void OpSet::Parse(ifstream& device)
{
	id = ByteArrayRead::ReadInt(device);
}
