#include "OpMaxStack.h"

void OpMaxStack::Run()
{
	frame->GetStack().SetMaxSize(size);
}

void OpMaxStack::Parse(QIODevice& device)
{
	size = ByteArrayRead::ReadInt(device);
}
