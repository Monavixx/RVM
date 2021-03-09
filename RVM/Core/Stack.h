#pragma once
#include "../Std/Classes/Object.h"
#include "../Functions/Exit.h"


class Stack
{
public:
	Stack() : stack(nullptr) {}
	void push(size_t index);
	Object* pop();
	size_t popAddress();

	Object* top();

	size_t& topAddress();

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
	size_t* stack;
};

