#pragma once
#include "IMethod.h"
#include "VariableList.h"
#include "../Std/RelaxNull.h"
#include "Stack.h"

class Frame
{
public:
	Frame(IMethod* method = nullptr, const VariableList& variableList = {});

	Variable* GetVariable(size_t id);

	IMethod* GetMethod() const;
	VariableList GetVariableList() const;

	void SetMethod(IMethod* method);
	void SetVariableList(const VariableList& variables);
	void CreateVariable(size_t id, const String& dataType);

	Stack& GetStack();
	
	class OpBase* Next();
	bool IsEnd();
	void SetIndex(size_t index);

private:
	VariableList variables;
	IMethod* method;
	Stack stack;

	size_t index = 0;
};

