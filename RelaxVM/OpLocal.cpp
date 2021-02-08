#include "OpLocal.h"

void OpLocal::Run()
{
	frame->CreateVariable(id, dataType);
}

void OpLocal::Parse(QIODevice& device)
{
	id = ByteArrayRead::ReadInt(device);
	dataType = ByteArrayRead::ReadSizeAndString(device);
}
