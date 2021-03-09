#include "OpPushBool.h"

void OpPushBool::Run()
{
	RelaxBool* pushingData = new RelaxBool(data);
	frame->GetStack().push(GlobalVariables::heap.push_back(pushingData));
}

void OpPushBool::Parse(HANDLE& device)
{
	data = (bool)ByteArrayRead::ReadByte(device);
}
