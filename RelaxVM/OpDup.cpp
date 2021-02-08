#include "OpDup.h"

void OpDup::Run()
{
	Object* data = frame->GetStack().pop();
	frame->GetStack().push(data);
	frame->GetStack().push(data);
}

void OpDup::Parse(QIODevice& device)
{
}
