#include "Stack.h"

void Stack::push(Object* object)
{
	if (currentSize+1 > maxSize)
		Exit("Stack is small");
	object->IncAmountUsers();
	
	stack[currentSize++] = object;
}

Object* Stack::pop()
{
	Object* poppedObject = stack[--currentSize];
	poppedObject->DecAmountUsers();
	return poppedObject;
}

bool Stack::isEmpty()
{
	return currentSize == 0;
}

Stack::~Stack()
{
	delete[] stack;
}
