#pragma once
#include <QtCore>
#include "Object.h"
#include "Functions/Exit.h"

class Stack
{
public:
	Stack();
	void push(Object*& object);
	Object*& pop();
	int size() const;
	bool isEmpty() const;

private:
	int _size;
	const int maxSize = 1048576 / sizeof(Object*);
	Object** objects;
};

