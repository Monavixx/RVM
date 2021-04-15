#pragma once
#include "IMethod.h"
#include "VariableList.h"
#include "Stack.h"
#include "../Libs/ConsoleTextStream.h"

class Frame
{
public:
	Frame(IMethod* method = nullptr, Object* objectThis = 0, const VariableList& variableList = {});
	~Frame();

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
	void CreateVariable(size_t id, Class* dataType);

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

	inline Object* GetObjectThis() const
	{
		return objectThis;
	}
	inline void SetObjectThis(Object* objectThis)
	{
		this->objectThis = objectThis;
	}
	inline Value* AddValue(Value* value)
	{
		values.push_back(value);
		return value;
	}

private:
	VariableList variables;
	IMethod* method;
	Stack stack;
	Object* objectThis;
	vector<Value*> values;

	size_t index = 0;
};

