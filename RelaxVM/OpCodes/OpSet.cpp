#include "OpSet.h"
#include "../Libs/ConsoleTextStream.h"

void OpSet::Run()
{
	Object* data = frame->GetStack().pop();
	Variable* variable = frame->GetVariable(id);
	if (variable == nullptr)
		Exit("set: local variable with id " + QString::number(id) + " not exists");

	/*QString f = variable->GetDataType();
	qout << f;*/
	if (data->GetDataType() == variable->GetDataType() || data->GetDataType() == "Relax.Null")
	{
		data->IncAmountUsers();
		variable->SetAddress(data->GetAddress());
	}
}

void OpSet::Parse(QIODevice& device)
{
	id = ByteArrayRead::ReadInt(device);
}
