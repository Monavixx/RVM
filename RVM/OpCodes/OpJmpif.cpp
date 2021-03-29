#include "OpJmpif.h"
#include "../Core/FieldObject.h"

void OpJmpif::Run()
{
	bool isTrue = frame->GetStack().pop()->value.boolean;
	if (isTrue)
	{
		frame->SetIndex(offset);
	}
}

void OpJmpif::Parse(ifstream& device)
{
	offset = ByteArrayRead::ReadInt(device);
}
