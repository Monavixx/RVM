#pragma once
#include "Method.h"
#include "VariableList.h"
#include "../Std/RelaxNull.h"
#include "Stack.h"

class Frame
{
public:
	Frame(Method* method = nullptr, const VariableList& variableList = {});

	Variable* GetVariable(size_t id);

	Method* GetMethod() const;
	VariableList GetVariableList() const;

	void SetMethod(Method* method);
	void SetVariableList(const VariableList& variables);
	void CreateVariable(size_t id, const String& dataType);

	Stack& GetStack();
	
	class OpBase* Next();
	bool IsEnd();
	void SetIndex(size_t index);

private:
	VariableList variables;
	Method* method;
	Stack stack;

	size_t index = 0;
};

