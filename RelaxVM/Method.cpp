#include "Method.h"

Method::Method(const MethodSignature& signature, const vector<OpBase*>& code, const AccessModifier& accessModifier, bool isStatic)
	: MethodSignature(signature), accessModifier(accessModifier), isStatic(isStatic), code(code)
{
}

Method::Method(const QString& name, const QString& dataType, const QString& nameClass, const vector<Parameter>& parameters,
	const vector<OpBase*>& code, const AccessModifier& accessModifier, bool isStatic)
	: MethodSignature(name, dataType, nameClass, parameters), accessModifier(accessModifier), isStatic(isStatic), code(code)
{
}

bool Method::IsStatic() const
{
	return isStatic;
}

AccessModifier Method::GetAccessModifier() const
{
	return accessModifier;
}

vector<OpBase*>& Method::GetCode()
{
	return this->code;
}

void Method::SetIsStatic(bool isStatic)
{
	this->isStatic = isStatic;
}

void Method::SetAccessModifier(const AccessModifier& accessModifier)
{
	this->accessModifier = accessModifier;
}

void Method::SetCode(const vector<OpBase*>& code)
{
	this->code = code;
}

bool Method::operator==(Method& other)
{
	if (!MethodSignature::operator==(dynamic_cast<MethodSignature&>(other)))
		return false;
	if (isStatic != other.IsStatic()) return false;
	if (accessModifier == other.GetAccessModifier()) return false;
	if (code == other.GetCode())return false;
	return true;
}
