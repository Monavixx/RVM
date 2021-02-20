#pragma once
#include <QtCore>
#include "MethodSignature.h"
#include "../Enums/AccessModifier.h"

class OpBase;

class Method : public MethodSignature
{
public:
	Method(const MethodSignature& signature, const QVector<OpBase*>& code = {}, const AccessModifier & accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	Method(const QString& name, const QString& dataType, const QString& nameClass, const QVector<Parameter>& parameters = {},
		const QVector<OpBase*>& code = {}, const AccessModifier& accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	bool IsStatic() const;
	AccessModifier GetAccessModifier() const;
	QVector<OpBase*>& GetCode();

	void SetIsStatic(bool isStatic);
	void SetAccessModifier(const AccessModifier& accessModifier);
	void SetCode(const QVector<OpBase*>& code);

	bool operator==(Method& other) const;

	void CallMethod(class Frame* frame);

private:
	AccessModifier accessModifier;
	bool isStatic;
	QVector<OpBase*> code;
};

