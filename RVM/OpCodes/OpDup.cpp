#include "OpDup.h"
#include "../Core/FieldObject.h"

void OpDup::Run()
{
	Value* data = frame->GetStack().pop();
	frame->GetStack().push(data);
	frame->GetStack().push(data);
}

void OpDup::Parse(HANDLE& device)
{
}
