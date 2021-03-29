#include "OpMaxStack.h"
#include "../Core/FieldObject.h"

void OpMaxStack::Run()
{
	frame->GetStack().SetMaxSize(size);
}

void OpMaxStack::Parse(ifstream& device)
{
	size = ByteArrayRead::ReadInt(device);
}
