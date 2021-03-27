#include "OpJmp.h"
#include "../Core/FieldObject.h"

void OpJmp::Run()
{
	frame->SetIndex(offset);
}

void OpJmp::Parse(HANDLE& device)
{
	offset = ByteArrayRead::ReadInt(device);
}
