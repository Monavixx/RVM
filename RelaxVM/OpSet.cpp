#include "OpSet.h"

void OpSet::Run()
{
	Object* data = frame->GetStack().pop();
	Variable* variable = frame->FindVariableById(id);
	if (variable == nullptr)
		Exit("set: local variable with id " + QString::number(id) + " not exists");

	if (data->GetDataType() == variable->GetData()->GetDataType())
	{
		data->IncAmountUsers();
		variable->SetData(data);
	}
}

void OpSet::Parse(QIODevice& device)
{
	id = ByteArrayRead::ReadInt(device);
}
