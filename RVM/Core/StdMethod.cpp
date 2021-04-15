#include "StdMethod.h"
#include "../Core/Frame.h"
#include "../GlobalVariables.h"
#include "FieldObject.h"

StdMethod::StdMethod(const String& name, const String& dataType, const std::vector<Parameter>& parameters, std::function<Value*(Stack&)> function, const AccessModifier& accessModifier, bool isStatic)
	:IMethod(name, dataType, parameters, accessModifier, isStatic), function(function)
{
}

void StdMethod::CallMethod(Frame* frame)
{
	Value* returnedObject = function(frame->GetStack());
	if (returnedObject->valueType != ValueType::_VOID)
	{
		frame->GetStack().push(frame->AddValue(returnedObject));
	}
}
