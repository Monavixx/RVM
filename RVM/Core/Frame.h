#pragma once
#include "IMethod.h"
#include "VariableList.h"
#include "../Std/RelaxNull.h"
#include "Stack.h"

class Frame
{
public:
	Frame(IMethod* method = nullptr, size_t objectThis = 0, const VariableList& variableList = {});

	inline Variable* GetVariable(size_t id)
	{
		return &variables[id];
	}

	inline IMethod* GetMethod() const
	{
		return method;
	}
	inline VariableList GetVariableList() const
	{
		return variables;
	}

	inline void SetMethod(IMethod* method)
	{
		this->method = method;
	}
	inline void SetVariableList(const VariableList& variables)
	{
		this->variables = variables;
	}
	void CreateVariable(size_t id, const String& dataType);

	inline Stack& GetStack()
	{
		return stack;
	}
	
	class OpBase* Next();
	bool IsEnd();
	
	inline void SetIndex(size_t index)
	{
		this->index = index;
	}

	inline size_t GetObjectThis() const
	{
		return objectThis;
	}
	inline void SetObjectThis(size_t objectThis)
	{
		this->objectThis = objectThis;
	}

private:
	VariableList variables;
	IMethod* method;
	Stack stack;
	size_t objectThis;

	size_t index = 0;
};

