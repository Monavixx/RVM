#include "Heap.h"

Heap::Heap()
{
}

Heap::Heap(const QVector<Object*>& variableList) : QVector<Object*>(variableList)
{
}

Heap::Heap(const Heap& variableList) : QVector<Object*>(variableList)
{
}