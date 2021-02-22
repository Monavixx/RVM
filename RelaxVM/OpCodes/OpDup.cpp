#include "OpDup.h"

void OpDup::Run()
{
	Object* data = frame->GetStack().pop();
	frame->GetStack().push(data->GetAddress());
	frame->GetStack().push(data->GetAddress());
}

void OpDup::Parse(QIODevice& device)
{
}
