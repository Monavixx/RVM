#include "VariableList.h"

VariableList::VariableList()
{
}

VariableList::VariableList(const unordered_map<int, Variable>& variables) : unordered_map<int, Variable>(variables)
{
}

VariableList::VariableList(const VariableList& variables) : unordered_map<int, Variable>(variables)
{
}
