#include "Heap.h"

Heap::Heap()
{
}

Heap::Heap(const list<Object*>& variableList)
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