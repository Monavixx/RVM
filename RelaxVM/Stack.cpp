#include "Stack.h"

void Stack::push(Object* object)
{
	if (stack == nullptr)
		stack = new Object* [maxSize];

	if (currentSize+1 > maxSize)
		Exit("Stack is small");
	object->IncAmountUsers();
	
	stack[currentSize++] = object;
}

Object* Stack::pop()
{
	Object* poppedObject = stack[--currentSize];
	stack[currentSize] = nullptr;
	poppedObject->DecAmountUsers();
	return poppedObject;
}

Object* Stack::top()
{
	return stack[currentSize-1];
}

bool Stack::isEmpty()
{
	return currentSize == 0;
}

Stack::~Stack()
{
	for (int i = 0; i < currentSize; ++i)
	{
		delete stack[i];
	}
	delete[] stack;
}

void Stack::SetMaxSize(int maxSize)
{
	this->maxSize = maxSize;
}
