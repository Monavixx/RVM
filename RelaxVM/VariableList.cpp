#include "VariableList.h"

VariableList::VariableList()
{
}

VariableList::VariableList(const QHash<int, Variable>& variables) : QHash<int, Variable>(variables)
{
}

VariableList::VariableList(const VariableList& variables) : QHash<int, Variable>(variables)
{
}
