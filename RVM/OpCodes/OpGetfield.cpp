#include "OpGetfield.h"
#include "../Core/FieldObject.h"

void OpGetfield::Run()
{
	Value* data = frame->GetStack().pop();
	frame->GetStack().push(get<Object*>(data->value)->GetField(name)->value);
}

void OpGetfield::Parse(ifstream& device)
{
	name = ByteArrayRead::ReadSizeAndString(device);
}
