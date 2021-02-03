#pragma once
#include <QtCore>
#include "Object.h"
#include "Functions/Exit.h"


class Stack
{
public:
	Stack(int maxSize) : maxSize(maxSize) {}
	void push(Object* object);
	Object* pop();
	bool isEmpty();
	~Stack();

private:
	int currentSize = 0;
	const int maxSize;
	Object** stack = new Object*[maxSize];
};

