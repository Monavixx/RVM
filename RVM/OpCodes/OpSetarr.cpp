#include "OpSetarr.h"
#include "../Core/FieldObject.h"

void OpSetarr::Run()
{
	RelaxArray* arr = dynamic_cast<RelaxArray*>(frame->GetStack().pop()->value.object);
	int index = frame->GetStack().pop()->value.inum;
	Value* data = frame->GetStack().pop();

	arr->SetByIndex(index, data);
}

void OpSetarr::Parse(HANDLE& device)
{
}
