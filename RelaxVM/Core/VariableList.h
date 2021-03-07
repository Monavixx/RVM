#pragma once
#include "Variable.h"
#include <unordered_map>

using std::unordered_map;

class VariableList : public unordered_map<int, Variable>
{
public:
	VariableList();
	VariableList(const unordered_map<int, Variable>& variables);
	VariableList(const VariableList& variables);
};

