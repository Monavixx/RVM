#include "Heap.h"

Heap::Heap()
{
}

Heap::Heap(const QList<Variable>& variableList)
{
    this->clear();
    for(auto& item : variableList)
    {
        this->push_back(item);
    }
}

Heap::Heap(const Heap& variableList)
{
    this->clear();
    for (auto& item : variableList)
    {
        this->push_back(item);
    }
}

Variable* Heap::FindVariableById(int id)
{
    auto heapIterator = std::find_if(this->begin(), this->end(), [&](const Variable& variable) {
        return variable.GetId() == id;
    });
    if(heapIterator == this->end())
        return nullptr;
    return &(*heapIterator);
}
