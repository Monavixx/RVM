#include "OpPushBool.h"

void OpPushBool::Run()
{
	RelaxBool* pushingData = new RelaxBool(data);
	gv->heap.push_back(pushingData);
	frame->GetStack().push(pushingData);
}

void OpPushBool::Parse(QIODevice& device)
{
	data = (bool)ByteArrayRead::ReadByte(device);
}
