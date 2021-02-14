#include "OpPushInt32.h"

void OpPushInt32::Run()
{
	RelaxInt32* pushingInt32 = new RelaxInt32(data);
	gv->heap.push_back(pushingInt32);
	frame->GetStack().push(pushingInt32);
}

void OpPushInt32::Parse(QIODevice& device)
{
	data = ByteArrayRead::ReadInt(device);
}
