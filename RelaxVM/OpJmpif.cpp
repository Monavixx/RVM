#include "OpJmpif.h"

void OpJmpif::Run()
{
	bool isTrue = dynamic_cast<RelaxBool*>(frame->GetStack().pop())->GetData();
	if (isTrue)
	{
		frame->SetIndex(offset);
	}
}

void OpJmpif::Parse(QIODevice& device)
{
	offset = ByteArrayRead::ReadInt(device);
}
