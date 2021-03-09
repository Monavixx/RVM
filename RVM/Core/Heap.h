#pragma once
#include "Variable.h"

class Heap
{
public:
	Heap(size_t maxSize);

	size_t push_back(Object* const& data);
	inline Object*& operator[](size_t index) {return heap[index];}
	inline size_t GetSize(){return size;}
	void Delete(size_t address);

private:
	size_t currentIndex;
	size_t size;
	size_t maxSize;
	Object** heap;
};

