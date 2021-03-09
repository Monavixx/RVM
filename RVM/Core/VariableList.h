#pragma once
#include "Variable.h"
#include <unordered_map>

using std::unordered_map;

class VariableList : public unordered_map<size_t, Variable>
{
public:
	VariableList();
	VariableList(const unordered_map<size_t, Variable>& variables);
	VariableList(const VariableList& variables);
};

