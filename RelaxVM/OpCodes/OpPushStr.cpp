#include "OpPushStr.h"

void OpPushStr::Run()
{
	RelaxString* pushingString = new RelaxString(data);
	gv->heap.push_back(pushingString);
	frame->GetStack().push(pushingString);
}

void OpPushStr::Parse(QIODevice& device)
{
	data = ByteArrayRead::ReadSizeAndString(device);
}
