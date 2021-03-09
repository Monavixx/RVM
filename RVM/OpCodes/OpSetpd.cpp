#include "OpSetpd.h"
#include "../Std/Classes/RelaxPointer.h"

void OpSetpd::Run()
{
	RelaxPointer* pointer = dynamic_cast<RelaxPointer*>(frame->GetStack().pop());
	Object* data = frame->GetStack().pop();
	pointer->SetPointerData(data);
}

void OpSetpd::Parse(HANDLE& device)
{
}
