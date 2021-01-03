#pragma once
#include <QtCore>
#include "MethodSignature.h"
#include "AccessModifier.h"

class Method : public MethodSignature
{
public:
	Method(const MethodSignature& signature, const QByteArray& code, const AccessModifier& accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	Method(const QString& name, const QString& dataType, const QString& nameClass, const QList<Parameter>& parameters = {},
		const QByteArray& code, const AccessModifier& accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	bool IsStatic() const;
	AccessModifier GetAccessModifier() const;
	QByteArray GetCode() const;

	void SetIsStatic(bool isStatic);
	void SetAccessModifier(const AccessModifier& accessModifier);
	void SetCode(const QByteArray& code);

	bool operator==(const Method& other) const;

private:
	AccessModifier accessModifier;
	bool isStatic;
	QByteArray code;
};

