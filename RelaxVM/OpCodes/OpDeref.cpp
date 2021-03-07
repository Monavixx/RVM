#include "OpDeref.h"
#include "../Std/DataTypes/RelaxPointer.h"

void OpDeref::Run()
{
	RelaxPointer* pointer = dynamic_cast<RelaxPointer*>(frame->GetStack().pop());
	frame->GetStack().push(pointer->GetPointerAddress());
}

void OpDeref::Parse(HANDLE& device)
{
}
