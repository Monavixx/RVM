#include "OpGetfield.h"

void OpGetfield::Run()
{
	Object* data = frame->GetStack().pop();
}

void OpGetfield::Parse(HANDLE& device)
{
	name = ByteArrayRead::ReadSizeAndString(device);
}
