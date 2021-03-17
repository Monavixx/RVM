#include "OpSetfield.h"

void OpSetfield::Run()
{
	Object* target = frame->GetStack().pop();
	size_t valueAddress = frame->GetStack().popAddress();
	target->SetField(name, valueAddress);
}

void OpSetfield::Parse(HANDLE& device)
{
	name = ByteArrayRead::ReadSizeAndString(device);
}
