#include "VariableList.h"

VariableList::VariableList()
{
}

VariableList::VariableList(const unordered_map<size_t, Variable>& variables) : unordered_map<size_t, Variable>(variables)
{
}

VariableList::VariableList(const VariableList& variables) : unordered_map<size_t, Variable>(variables)
{
}
