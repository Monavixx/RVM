#include "OpNewarr.h"

void OpNewarr::Run()
{
	int arraySize = dynamic_cast<RelaxInt32*>(frame->GetStack().pop())->GetData();
	RelaxArray* newArray = new RelaxArray(dataType, arraySize);
	gv->heap.push_back(newArray);
	frame->GetStack().push(newArray);
}

void OpNewarr::Parse(QIODevice& device)
{
	dataType = ByteArrayRead::ReadSizeAndString(device);
}
