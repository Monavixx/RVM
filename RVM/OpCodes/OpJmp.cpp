#include "OpJmp.h"

void OpJmp::Run()
{
	frame->SetIndex(offset);
}

void OpJmp::Parse(HANDLE& device)
{
	offset = ByteArrayRead::ReadInt(device);
}
