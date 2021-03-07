#include "OpSet.h"
#include "../Libs/ConsoleTextStream.h"

void OpSet::Run()
{
	Object* data = frame->GetStack().pop();
	Variable* variable = frame->GetVariable(id);
	if (variable == nullptr)
		Exit("set: local variable with id " + std::to_string(id) + " not exists");

	
	if (data->GetDataType() != variable->GetDataType() && data->GetDataType() != "Relax.Null")
		Exit("set: data types do not match");

	Object* oldData = GlobalVariables::heap[variable->GetAddress()];
	if(oldData != nullptr) oldData->DecAmountUsers();

	data->IncAmountUsers();
	variable->SetAddress(data->GetAddress());
}

void OpSet::Parse(HANDLE& device)
{
	id = ByteArrayRead::ReadInt(device);
}
