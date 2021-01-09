#include "VariableList.h"

VariableList::VariableList()
{
}

VariableList::VariableList(const QList<Variable>& variables)
{
    this->clear();
    for (auto& item : variables)
    {
        this->push_back(item);
    }
}

VariableList::VariableList(const VariableList& variables)
{
    this->clear();
    for (auto& item : variables)
    {
        this->push_back(item);
    }
}

Variable* VariableList::FindVariableById(int id)
{
    auto variableIterator = std::find_if(this->begin(), this->end(), [&](const Variable& variable) {
        return variable.GetId() == id;
    });
    if(variableIterator == this->end())
        return nullptr;
    return &(*variableIterator);
}

