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

	inline bool isEmpty()
	{
		return currentSize <= 0;
	}

	~Stack();

	inline void SetMaxSize(int maxSize)
	{
		this->maxSize = maxSize;
	}

private:
	int currentSize = 0;
	int maxSize = 0;
	int* stack;
};

