#pragma once
#include <QtCore>
#include "../Std/DataTypes/Object.h"
#include "../Functions/Exit.h"


class Stack
{
public:
	Stack() : stack(nullptr) {}
	void push(int index);
	Object* pop();
	int popIndex();
	Object* top();
	int& topIndex();
	bool isEmpty();
	~Stack();
	void SetMaxSize(int maxSize);

private:
	int currentSize = 0;
	int maxSize = 0;
	int* stack;
};

