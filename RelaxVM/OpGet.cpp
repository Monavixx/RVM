#include "OpGet.h"

void OpGet::Run()
{
	Variable* variable = frame->GetVariable(id);
	if (variable == nullptr)
		Exit("get: local variable with id " + QString::number(id) + " not exists");

	Object* data = variable->GetData();
	frame->GetStack().push(data);
}

void OpGet::Parse(QIODevice& device)
{
	id = ByteArrayRead::ReadInt(device);
}
