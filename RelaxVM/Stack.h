#pragma once
#include <QtCore>
#include "Object.h"
#include "Functions/Exit.h"


class Stack
{
public:
	Stack() : stack(nullptr) {}
	void push(Object* object);
	Object* pop();
	Object* top();
	bool isEmpty();
	~Stack();
	void SetMaxSize(int maxSize);

private:
	int currentSize = 0;
	int maxSize = 0;
	Object** stack;
};

