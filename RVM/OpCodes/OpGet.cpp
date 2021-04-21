#include "OpGet.h"
#include "../Core/FieldObject.h"

void OpGet::Run()
{
	Variable* variable = frame->GetVariable(id);
	if (variable == nullptr)
		Exit("get: local variable with id "_ss + id + " not exists"_ss, 19);

	frame->GetStack().push(variable->GetValue());
}

void OpGet::Parse(ifstream& device)
{
	id = ByteArrayRead::ReadInt(device);
}
