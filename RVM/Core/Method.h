#pragma once
#include "IMethod.h"
#include "../Enums/AccessModifier.h"

class OpBase;

class Method : public IMethod
{
public:
	Method(const String& name, const String& dataType, const String& declClassName, const vector<Parameter>& parameters = {},
		const vector<OpBase*>& code = {}, const AccessModifier& accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	inline vector<OpBase*>& GetCode() { return this->code; }
	inline void SetCode(const vector<OpBase*>& code) { this->code = code; }
	inline void AddOpCode(OpBase* opCode) { this->code.push_back(opCode); }

	void CallMethod(class Frame* frame) override;

private:
	vector<OpBase*> code;
};

