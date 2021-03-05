#include "Stack.h"
#include "../GlobalVariables.h"

void Stack::push(int index)
{
	if (stack == nullptr)
		stack = new int [maxSize];

	if (currentSize+1 > maxSize)
		Exit("Stack is small");

	GlobalVariables::heap[index]->IncAmountUsers();
	
	stack[currentSize++] = index;
}

Object* Stack::pop()
{
	if (currentSize <= 0)
		Exit("Stack is empty");
	Object* poppedObject = GlobalVariables::heap[stack[--currentSize]];
	poppedObject->DecAmountUsers();
	return poppedObject;
}

int Stack::popIndex()
{
	return 0;
}

Object* Stack::top()
{
	if (currentSize <= 0)
		Exit("Stack is empty");
	return GlobalVariables::heap[stack[currentSize - 1]];
}

int& Stack::topIndex()
{
	if (currentSize <= 0)
		Exit("Stack is empty");
	return stack[currentSize - 1];
}

Stack::~Stack()
{
	delete[] stack;
}
