#include "OpGetarr.h"
#include "../Core/FieldObject.h"

void OpGetarr::Run()
{
	RelaxArray* arr = dynamic_cast<RelaxArray*>(frame->GetStack().pop()->value.object);
	int index = frame->GetStack().pop()->value.inum;
	frame->GetStack().push(arr->GetByIndex(index));
}

void OpGetarr::Parse(ifstream& device)
{
}
