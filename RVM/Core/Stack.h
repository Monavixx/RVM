#pragma once
#include "Value.h"
#include "../Functions/Exit.h"


class Stack
{
public:
	Stack() : stack(nullptr) {}
	void push(Value* value);
	Value* pop();

	Value* top();

	inline bool isEmpty()
	{
		return currentSize <= 0;
	}

	~Stack();

	inline void SetMaxSize(size_t maxSize)
	{
		this->maxSize = maxSize;
	}

private:
	size_t currentSize = 0;
	size_t maxSize = 0;
	Value** stack;
};

