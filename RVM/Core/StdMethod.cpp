#include "StdMethod.h"
#include "../Core/Frame.h"
#include "../GlobalVariables.h"

StdMethod::StdMethod(const String& name, const String& dataType, const String& declClassName, const std::vector<Parameter>& parameters, std::function<Object*(Stack&)> function, const AccessModifier& accessModifier, bool isStatic)
	:IMethod(name, dataType, declClassName, parameters, accessModifier, isStatic), function(function)
{
}

void StdMethod::CallMethod(Frame* frame)
{
	Object* returnedObject = function(frame->GetStack());
	if (returnedObject != nullptr)
	{
		GlobalVariables::heap.push_back(returnedObject);
		frame->GetStack().push(returnedObject->GetAddress());
	}
}
