#include "OpSetfield.h"

void OpSetfield::Run()
{
	Object* target = frame->GetStack().pop();
	Object* value = frame->GetStack().pop();
	if (target->GetField(name).field->GetDataType() != value->GetDataType())
		Exit("setfield: data types do not match");
	value->IncAmountUsers();
	target->SetField(name, value->GetAddress());
}

void OpSetfield::Parse(HANDLE& device)
{
	name = ByteArrayRead::ReadSizeAndString(device);
}
