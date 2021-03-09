#include "Heap.h"
#include "../Functions/GC.h"

Heap::Heap(size_t maxSize) : maxSize(maxSize), size(0), currentIndex(0)
{
	heap = new Object*[maxSize] {nullptr};
}

size_t Heap::push_back(Object* const& data)
{
	while (true)
	{
		if (heap[currentIndex] == nullptr)
			break;
		else if (heap[currentIndex]->GetAmountUsers() <= 0)
		{
			Delete(currentIndex);
			break;
		}
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


void Heap::Delete(size_t address)
{
	if (heap[address] != nullptr)
	{
		delete heap[address];
		heap[address] = nullptr;
	}
}
