#include "OpPushFloat.h"

void OpPushFloat::Run()
{
	RelaxFloat* pushingData = new RelaxFloat(data);
	frame->GetStack().push(GlobalVariables::heap.push_back(pushingData));
}

void OpPushFloat::Parse(HANDLE& device)
{
	data = ByteArrayRead::ReadFloat(device);
}
