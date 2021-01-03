#pragma once
#include <QtCore>
#include "MethodSignature.h"
#include "AccessModifier.h"

class Method : public MethodSignature
{
public:
	Method(const MethodSignature& signature, const AccessModifier& accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	Method(const QString& name, const QString& dataType, const QString& nameClass, const QList<Parameter>& parameters = {},
		const AccessModifier& accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	bool IsStatic() const;
	AccessModifier GetAccessModifier() const;

	void SetIsStatic(bool isStatic);
	void SetAccessModifier(const AccessModifier& accessModifier);

	bool operator==(const Method& other) const;

private:
	AccessModifier accessModifier;
	bool isStatic;
};

