#include "OpGet.h"

void OpGet::Run()
{
	Variable* variable = frame->GetVariable(id);
	if (variable == nullptr)
		Exit("get: local variable with id " + std::to_string(id) + " not exists");

	frame->GetStack().push(variable->GetAddress());
}

void OpGet::Parse(HANDLE& device)
{
	id = ByteArrayRead::ReadInt(device);
}
