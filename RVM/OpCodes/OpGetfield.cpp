#include "OpGetfield.h"
#include "../Core/FieldObject.h"

void OpGetfield::Run()
{
	Value* data = frame->GetStack().pop();
	frame->GetStack().push(GlobalVariables::heap[get<size_t>(data->value)]->GetField(name)->value);
}

void OpGetfield::Parse(ifstream& device)
{
	name = ByteArrayRead::ReadSizeAndString(device);
}
