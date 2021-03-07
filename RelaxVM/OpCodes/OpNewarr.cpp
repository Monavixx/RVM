#include "OpNewarr.h"

void OpNewarr::Run()
{
	int arraySize = dynamic_cast<RelaxInt32*>(frame->GetStack().pop())->GetData();
	RelaxArray* newArray = new RelaxArray(dataType, arraySize);
	frame->GetStack().push(GlobalVariables::heap.push_back(newArray));
}

void OpNewarr::Parse(HANDLE& device)
{
	dataType = ByteArrayRead::ReadSizeAndString(device);
}
