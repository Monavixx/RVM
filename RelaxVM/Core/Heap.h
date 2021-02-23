#pragma once
#include <QtCore>
#include "Variable.h"

class Heap
{
public: 
	Heap(int maxSize);

	int push_back(Object* const& data);
	Object*& operator[](int index);
	int GetSize() { return size; }
	void Delete(int address);

private:
	int currentIndex;
	int size;
	int maxSize;
	Object** heap;
};

