#include "OpGetfield.h"

void OpGetfield::Run()
{
	Object* data = frame->GetStack().pop();
	frame->GetStack().push(data->GetField(name).address);
}

void OpGetfield::Parse(HANDLE& device)
{
	name = ByteArrayRead::ReadSizeAndString(device);
}
