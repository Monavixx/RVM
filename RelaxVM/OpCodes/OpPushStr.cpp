#include "OpPushStr.h"

void OpPushStr::Run()
{
	RelaxString* pushingString = new RelaxString(data);
	frame->GetStack().push(GlobalVariables::heap.push_back(pushingString));
}

void OpPushStr::Parse(QIODevice& device)
{
	data = ByteArrayRead::ReadSizeAndString(device);
}
