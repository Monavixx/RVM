#include "OpReturn.h"

void OpReturn::Run()
{
	Object* data = frame->GetStack().pop();
	if (frame->GetMethod()->GetDataType() != data->GetDataType())
		Exit("Error return data type");
	gv->frameStack.pop();
	delete gv->frameStack.top();
	gv->frameStack.top()->GetStack().push(data);
}

void OpReturn::Parse(QIODevice& device)
{
}
