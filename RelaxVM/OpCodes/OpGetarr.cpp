#include "OpGetarr.h"

void OpGetarr::Run()
{
	RelaxArray* arr = dynamic_cast<RelaxArray*>(frame->GetStack().pop());
	int index = dynamic_cast<RelaxInt32*>(frame->GetStack().pop())->GetData();
	frame->GetStack().push(arr->GetByIndex(index));
}

void OpGetarr::Parse(HANDLE& device)
{
}
