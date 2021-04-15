#include "OpSetfield.h"
#include "../Core/FieldObject.h"

void OpSetfield::Run()
{
	Object* target = GlobalVariables::heap[get<size_t>(frame->GetStack().pop()->value)];
	Value* value = frame->GetStack().pop();

	target->SetField(name, value);
}

void OpSetfield::Parse(ifstream& device)
{
	name = ByteArrayRead::ReadSizeAndString(device);
}
