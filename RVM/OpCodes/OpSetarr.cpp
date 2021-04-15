#include "OpSetarr.h"
#include "../Core/FieldObject.h"

void OpSetarr::Run()
{
	RelaxArray* arr = dynamic_cast<RelaxArray*>(GlobalVariables::heap[get<size_t>(frame->GetStack().pop()->value)]);
	int index = get<int>(frame->GetStack().pop()->value);
	Value* data = frame->GetStack().pop();
	arr->SetByIndex(index, data);
}

void OpSetarr::Parse(ifstream& device)
{
}
