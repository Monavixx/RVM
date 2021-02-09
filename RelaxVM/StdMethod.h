#pragma once
#include <QtCore>
#include "MethodSignature.h"
#include "AccessModifier.h"
#include "Stack.h"

class StdMethod : public MethodSignature
{
public:
	StdMethod(const MethodSignature& signature, std::function<Object* (Stack&)> function = {}, const AccessModifier& accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	StdMethod(const QString& name, const QString& dataType, const QString& nameClass, const QList<Parameter>& parameters = {},
		std::function<Object*(Stack&)> code = {}, const AccessModifier& accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	bool IsStatic() const;
	AccessModifier GetAccessModifier() const;
	std::function<Object*(Stack&)> GetFunction() const;

	void SetIsStatic(bool isStatic);
	void SetAccessModifier(const AccessModifier& accessModifier);
	void SetFunction(std::function<Object*(Stack&)> function);

	Object* CallFunction(Stack& stack);

	bool operator==(const StdMethod& other) const;
private:
	std::function<Object*(Stack&)> function;
	AccessModifier accessModifier;
	bool isStatic;
};

