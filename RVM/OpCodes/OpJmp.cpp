#include "OpJmp.h"
#include "../Core/FieldObject.h"

void OpJmp::Run()
{
	frame->SetIndex(offset);
}

void OpJmp::Parse(ifstream& device)
{
	offset = ByteArrayRead::ReadInt(device);
}
