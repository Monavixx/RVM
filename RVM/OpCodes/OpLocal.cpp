#include "OpLocal.h"
#include "../Core/FieldObject.h"

void OpLocal::Run()
{
	frame->CreateVariable(id, dataType);
}

void OpLocal::Parse(HANDLE& device)
{
	id = ByteArrayRead::ReadInt(device);
	dataType = ByteArrayRead::ReadSizeAndString(device);
}
