#include "OpSetarr.h"

void OpSetarr::Run()
{
	RelaxArray* arr = dynamic_cast<RelaxArray*>(frame->GetStack().pop());
	int index = dynamic_cast<RelaxInt32*>(frame->GetStack().pop())->GetData();
	Object* data = frame->GetStack().pop();

	arr->SetByIndex(index, data);
}

void OpSetarr::Parse(QIODevice& device)
{
}
