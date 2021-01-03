#include "Method.h"

Method::Method(const MethodSignature& signature, const AccessModifier& accessModifier, bool isStatic)
	: MethodSignature(signature), accessModifier(accessModifier), isStatic(isStatic)
{
}

Method::Method(const QString& name, const QString& dataType, const QString& nameClass, const QList<Parameter>& parameters,
	const AccessModifier& accessModifier, bool isStatic)
	: MethodSignature(name, dataType, nameClass, parameters), accessModifier(accessModifier), isStatic(isStatic)
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

void Method::SetIsStatic(bool isStatic)
{
	this->isStatic = isStatic;
}

void Method::SetAccessModifier(const AccessModifier& accessModifier)
{
	this->accessModifier = accessModifier;
}

bool Method::operator==(const Method& other) const
{
	bool signatureIsEqual = MethodSignature::operator==(dynamic_cast<const MethodSignature&>(other));
	bool isStaticIsEqual = isStatic == other.IsStatic();
	bool accessModifierIsEqual = accessModifier == other.GetAccessModifier();
	return signatureIsEqual && isStaticIsEqual && accessModifierIsEqual;
}
