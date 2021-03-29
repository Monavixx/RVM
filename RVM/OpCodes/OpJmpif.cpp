#include "OpJmpif.h"
#include "../Core/FieldObject.h"

void OpJmpif::Run()
{
	bool isTrue = get<bool>(frame->GetStack().pop()->value);
	if (isTrue)
	{
		frame->SetIndex(offset);
	}
}

void OpJmpif::Parse(ifstream& device)
{
	offset = ByteArrayRead::ReadInt(device);
}
