#pragma once
#include <QtCore>
#include "Variable.h"

class VariableList : public QList<Variable>
{
public:
	VariableList();
	VariableList(const QList<Variable>& variables);
	VariableList(const VariableList& variables);

	Variable* FindVariableById(int id);
};

