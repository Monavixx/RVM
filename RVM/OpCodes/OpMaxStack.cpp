#include "OpMaxStack.h"

void OpMaxStack::Run()
{
	frame->GetStack().SetMaxSize(size);
}

void OpMaxStack::Parse(HANDLE& device)
{
	size = ByteArrayRead::ReadInt(device);
}
