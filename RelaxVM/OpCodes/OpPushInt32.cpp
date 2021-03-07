#include "OpPushInt32.h"

void OpPushInt32::Run()
{
	RelaxInt32* pushingInt32 = new RelaxInt32(data);
	frame->GetStack().push(GlobalVariables::heap.push_back(pushingInt32));
}

void OpPushInt32::Parse(HANDLE& device)
{
	data = ByteArrayRead::ReadInt(device);
}
