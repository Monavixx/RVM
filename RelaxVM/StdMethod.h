#pragma once
#include <QtCore>
#include "MethodSignature.h"
#include "AccessModifier.h"
#include "Stack.h"

class StdMethod : public MethodSignature
{
public:
	StdMethod(const MethodSignature& signature, std::function<void(Stack&)> function = {}, const AccessModifier& accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	StdMethod(const QString& name, const QString& dataType, const QString& nameClass, const QList<Parameter>& parameters = {},
		std::function<void(Stack&)> code = {}, const AccessModifier& accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	bool IsStatic() const;
	AccessModifier GetAccessModifier() const;
	std::function<void(Stack&)> GetFunction() const;

	void SetIsStatic(bool isStatic);
	void SetAccessModifier(const AccessModifier& accessModifier);
	void SetFunction(std::function<void(Stack&)> function);

	void CallFunction(Stack& stack);

	bool operator==(const StdMethod& other) const;
private:
	std::function<void(Stack&)> function;
	AccessModifier accessModifier;
	bool isStatic;
};

