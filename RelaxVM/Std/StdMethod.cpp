#include "StdMethod.h"
#include "../Core/Frame.h"
#include "../GlobalVariables.h"

StdMethod::StdMethod(const MethodSignature& signature, std::function<Object*(Stack&)> function, const AccessModifier& accessModifier, bool isStatic)
	: MethodSignature(signature), function(function), accessModifier(accessModifier), isStatic(isStatic)
{
}

StdMethod::StdMethod(const QString& name, const QString& dataType, const QString& nameClass, const QVector<Parameter>& parameters, std::function<Object*(Stack&)> function, const AccessModifier& accessModifier, bool isStatic)
	:MethodSignature(name, dataType, nameClass, parameters), function(function), accessModifier(accessModifier), isStatic(isStatic)
{
}

bool StdMethod::IsStatic() const
{
	return isStatic;
}

AccessModifier StdMethod::GetAccessModifier() const
{
	return accessModifier;
}

std::function<Object*(Stack&)> StdMethod::GetFunction() const
{
	return function;
}

void StdMethod::SetIsStatic(bool isStatic)
{
	this->isStatic = isStatic;
}

void StdMethod::SetAccessModifier(const AccessModifier& accessModifier)
{
	this->accessModifier = accessModifier;
}

void StdMethod::SetFunction(std::function<Object*(Stack&)> function)
{
	this->function = function;
}

void StdMethod::CallFunction(Frame* frame)
{
	Object* returnedObject = function(frame->GetStack());
	if (returnedObject != nullptr)
	{
		GlobalVariables::heap.push_back(returnedObject);
		frame->GetStack().push(returnedObject);
	}
}

bool StdMethod::operator==(const StdMethod& other) const
{
	if (!MethodSignature::operator==(dynamic_cast<const MethodSignature&>(other))) return false;
	if (isStatic != other.IsStatic()) return false;
	if (accessModifier != other.GetAccessModifier()) return false;
	return true;
}
