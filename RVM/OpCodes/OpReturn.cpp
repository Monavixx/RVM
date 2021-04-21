#include "OpReturn.h"
#include "../Core/FieldObject.h"

void OpReturn::Run()
{
	Value* data = frame->GetStack().pop();
	data = new Value(data->valueType, data->value);
	delete GlobalVariables::frameStack.top();
	GlobalVariables::frameStack.pop();
	GlobalVariables::frameStack.top()->GetStack().push(GlobalVariables::frameStack.top()->AddValue(data));
}

void OpReturn::Parse(ifstream& device)
{
}
