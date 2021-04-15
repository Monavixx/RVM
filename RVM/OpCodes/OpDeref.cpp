#include "OpDeref.h"
#include "../Core/FieldObject.h"
#include "../Std/Classes/RelaxPointer.h"

void OpDeref::Run()
{
	Value* value = frame->GetStack().pop();
	RelaxPointer* pointer = dynamic_cast<RelaxPointer*>(GlobalVariables::heap[get<size_t>(value->value)]);
	frame->GetStack().push(pointer->GetData());
}

void OpDeref::Parse(ifstream& device)
{
}
