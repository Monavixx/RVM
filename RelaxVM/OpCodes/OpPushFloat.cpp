#include "OpPushFloat.h"

void OpPushFloat::Run()
{
	RelaxFloat* pushingData = new RelaxFloat(data);
	GlobalVariables::heap.push_back(pushingData);
	frame->GetStack().push(pushingData);
}

void OpPushFloat::Parse(QIODevice& device)
{
	data = ByteArrayRead::ReadFloat(device);
}
