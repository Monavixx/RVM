#pragma once
#include <QtCore>
#include "Method.h"
#include "VariableList.h"
#include "RelaxNull.h"
#include "Stack.h"

class Frame
{
public:
	Frame(Method* method = nullptr, const VariableList& variableList = {});

	Variable* FindVariableById(int id);

	Method* GetMethod() const;
	VariableList GetVariableList() const;

	void SetMethod(Method* method);
	void SetVariableList(const VariableList& variables);
	void CreateVariable(int id, const QString& dataType);

	Stack& GetStack();

private:
	VariableList variables;
	Method* method;
	Stack stack;
};

