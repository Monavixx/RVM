#include "OpGetfield.h"
#include "../Core/FieldObject.h"

void OpGetfield::Run()
{
	Value* data = frame->GetStack().pop();
	frame->GetStack().push(data->value.object->GetField(name)->value);
}

void OpGetfield::Parse(HANDLE& device)
{
	name = ByteArrayRead::ReadSizeAndString(device);
}
