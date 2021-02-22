#include "OpSetpd.h"
#include "../Std/DataTypes/RelaxPointer.h"

void OpSetpd::Run()
{
	RelaxPointer* pointer = dynamic_cast<RelaxPointer*>(frame->GetStack().pop());
	Object* data = frame->GetStack().pop();
	pointer->SetPointerData(data);
}

void OpSetpd::Parse(QIODevice& device)
{
}
