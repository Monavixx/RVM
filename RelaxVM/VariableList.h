#pragma once
#include <QtCore>
#include "Variable.h"

class VariableList : public QHash<int, Variable>
{
public:
	VariableList();
	VariableList(const QHash<int, Variable>& variables);
	VariableList(const VariableList& variables);
};

