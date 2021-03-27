#include "OpSetpd.h"
#include "../Core/FieldObject.h"
#include "../Std/Classes/RelaxPointer.h"

void OpSetpd::Run()
{
	RelaxPointer* pointer = dynamic_cast<RelaxPointer*>(frame->GetStack().pop()->value.object);
	Value* data = frame->GetStack().pop();
	pointer->SetData(data);
}

void OpSetpd::Parse(HANDLE& device)
{
}
