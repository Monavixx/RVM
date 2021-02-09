#pragma once
#include <QtCore>
#include "MethodSignature.h"
#include "AccessModifier.h"

class Method : public MethodSignature
{
public:
	Method(const MethodSignature& signature, const QList<class OpBase*>& code = {}, const AccessModifier & accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	Method(const QString& name, const QString& dataType, const QString& nameClass, const QList<Parameter>& parameters = {},
		const QList<OpBase*>& code = {}, const AccessModifier& accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	bool IsStatic() const;
	AccessModifier GetAccessModifier() const;
	QList<OpBase*>& GetCode();

	void SetIsStatic(bool isStatic);
	void SetAccessModifier(const AccessModifier& accessModifier);
	void SetCode(const QList<OpBase*>& code);

	bool operator==(Method& other) const;

private:
	AccessModifier accessModifier;
	bool isStatic;
	QList<OpBase*> code;
};

