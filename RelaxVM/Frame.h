#pragma once
#include <QtCore>
#include "Method.h"
#include "VariableList.h"

class Frame
{
public:
	Frame(Method* method = nullptr, const VariableList& variableList = {});

	Variable* FindVariableById(int id);

	Method* GetMethod() const;
	VariableList GetVariableList() const;

	void SetMethod(Method* method);
	void SetVariableList(const VariableList& variables);

private:
	VariableList variables;
	Method* method;
};

