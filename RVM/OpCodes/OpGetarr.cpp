#include "OpGetarr.h"
#include "../Core/FieldObject.h"

void OpGetarr::Run()
{
	RelaxArray* arr = dynamic_cast<RelaxArray*>(get<Object*>(frame->GetStack().pop()->value));
	int index = get<int>(frame->GetStack().pop()->value);
	frame->GetStack().push(arr->GetByIndex(index));
}

void OpGetarr::Parse(ifstream& device)
{
}
