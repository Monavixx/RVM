#pragma once
#include <QtCore>
#include "MethodSignature.h"
#include "AccessModifier.h"

using std::vector;
class OpBase;

class Method : public MethodSignature
{
public:
	Method(const MethodSignature& signature, const vector<OpBase*>& code = {}, const AccessModifier & accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	Method(const QString& name, const QString& dataType, const QString& nameClass, const vector<Parameter>& parameters = {},
		const vector<OpBase*>& code = {}, const AccessModifier& accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	bool IsStatic() const;
	AccessModifier GetAccessModifier() const;
	vector<OpBase*>& GetCode();

	void SetIsStatic(bool isStatic);
	void SetAccessModifier(const AccessModifier& accessModifier);
	void SetCode(const vector<OpBase*>& code);

	bool operator==(Method& other);

private:
	AccessModifier accessModifier;
	bool isStatic;
	vector<OpBase*> code;
};

