#include "Heap.h"

Heap::Heap()
{
}

Heap::Heap(const QList<Object*>& variableList)
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
