#include "OpReturn.h"

void OpReturn::Run()
{
	Object* data = frame->GetStack().pop();
	if (frame->GetMethod()->GetDataType() != data->GetDataType())
		Exit("Error return data type");
	delete GlobalVariables::frameStack.top();
	GlobalVariables::frameStack.pop();
	GlobalVariables::frameStack.top()->GetStack().push(data->GetAddress());
}

void OpReturn::Parse(HANDLE& device)
{
}
