#include "OpReturn.h"
#include "../Core/FieldObject.h"

void OpReturn::Run()
{
	Value* data = frame->GetStack().pop();
	data = new Value(data->valueType, data->value);
	if (frame->GetMethod()->GetDataType() != Value::GetDataType(data))
		Exit("Error return data type");
	delete GlobalVariables::frameStack.top();
	GlobalVariables::frameStack.pop();
	GlobalVariables::frameStack.top()->GetStack().push(GlobalVariables::frameStack.top()->AddValue(data));
}

void OpReturn::Parse(HANDLE& device)
{
}
