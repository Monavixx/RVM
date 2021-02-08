#include "OpJmp.h"

void OpJmp::Run()
{
	frame->SetIndex(offset);
}

void OpJmp::Parse(QIODevice& device)
{
	offset = ByteArrayRead::ReadInt(device);
}
