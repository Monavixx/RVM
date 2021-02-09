#pragma once
#include <QtCore>
#include "Variable.h"

class VariableList : public std::unordered_map<int, Variable>
{
public:
	VariableList();
	VariableList(const unordered_map<int, Variable>& variables);
	VariableList(const VariableList& variables);
};

