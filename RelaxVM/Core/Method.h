#pragma once
#include "MethodSignature.h"
#include "../Enums/AccessModifier.h"

class OpBase;

class Method : public MethodSignature
{
public:
	Method(const MethodSignature& signature, const vector<OpBase*>& code = {}, const AccessModifier & accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	Method(const String& name, const String& dataType, const String& nameClass, const vector<Parameter>& parameters = {},
		const vector<OpBase*>& code = {}, const AccessModifier& accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	inline bool IsStatic() const { return isStatic; }

	inline AccessModifier GetAccessModifier() const { return accessModifier; }
	inline vector<OpBase*>& GetCode() { return this->code; }


	inline void SetIsStatic(bool isStatic) { this->isStatic = isStatic; }
	inline void SetAccessModifier(const AccessModifier& accessModifier) { this->accessModifier = accessModifier; }
	inline void SetCode(const vector<OpBase*>& code) { this->code = code; }
	inline void AddOpCode(OpBase* opCode) { this->code.push_back(opCode); }

	bool operator==(Method& other) const;

	void CallMethod(class Frame* frame);

private:
	AccessModifier accessModifier;
	bool isStatic;
	vector<OpBase*> code;
};

