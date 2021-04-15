#pragma once
#include <vector>
#include <functional>
#include "IMethod.h"
#include "../Enums/AccessModifier.h"
#include "Stack.h"
#include "Frame.h"

class StdMethod : public IMethod
{
public:
	StdMethod(const String& name, const String& dataType, const std::vector<Parameter>& parameters = {},
		std::function<Value*(Stack&)> code = {}, const AccessModifier& accessModifier = AccessModifier::PRIVATE, bool isStatic = false);

	inline std::function<Value* (Stack&)> GetFunction() const { return function; }

	inline void SetFunction(std::function<Value*(Stack&)> function) { this->function = function; }

	void CallMethod(Frame* frame) override;

private:
	std::function<Value* (Stack&)> function;
};

