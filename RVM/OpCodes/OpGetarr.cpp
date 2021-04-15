#include "OpGetarr.h"
#include "../Core/FieldObject.h"

void OpGetarr::Run()
{
	RelaxArray* arr = dynamic_cast<RelaxArray*>(GlobalVariables::heap[get<size_t>(frame->GetStack().pop()->value)]);
	int index = get<int>(frame->GetStack().pop()->value);
	frame->GetStack().push(arr->GetByIndex(index));
}

void OpGetarr::Parse(ifstream& device)
{
}
