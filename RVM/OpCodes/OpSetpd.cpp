#include "OpSetpd.h"
#include "../Core/FieldObject.h"
#include "../Std/Classes/RelaxPointer.h"

void OpSetpd::Run()
{
	RelaxPointer* pointer = dynamic_cast<RelaxPointer*>(GlobalVariables::heap[get<size_t>(frame->GetStack().pop()->value)]);
	Value* data = frame->GetStack().pop();
	pointer->SetData(data);
}

void OpSetpd::Parse(ifstream& device)
{
}
