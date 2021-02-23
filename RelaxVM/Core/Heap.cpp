#include "Heap.h"

Heap::Heap(int maxSize) : maxSize(maxSize)
{
	heap = new Object*[maxSize] {nullptr};
}

int Heap::push_back(Object* const& data)
{
	while (true)
	{
		if (heap[currentIndex] == nullptr)
			break;
		++currentIndex;
		if (currentIndex >= maxSize)
		{
			currentIndex = 0;
		}
	}
	data->SetAddress(currentIndex);
	heap[currentIndex] = data;

	if(size != maxSize) ++size;
	return currentIndex;
}

Object*& Heap::operator[](int index)
{
	return heap[index];
}

void Heap::Delete(int address)
{
	if (heap[address] != nullptr)
	{
		delete heap[address];
		heap[address] = nullptr;
	}
}
