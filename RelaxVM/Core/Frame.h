#pragma once
#include <QtCore>
#include "Method.h"
#include "VariableList.h"
#include "../Std/RelaxNull.h"
#include "Stack.h"

class Frame
{
public:
	Frame(Method* method = nullptr, const VariableList& variableList = {});

	Variable* GetVariable(int id);

	Method* GetMethod() const;
	VariableList GetVariableList() const;

	void SetMethod(Method* method);
	void SetVariableList(const VariableList& variables);
	void CreateVariable(int id, const QString& dataType);

	Stack& GetStack();
	
	class OpBase* Next();
	bool IsEnd();
	void SetIndex(int index);

private:
	VariableList variables;
	Method* method;
	Stack stack;

	int index = 0;
};

