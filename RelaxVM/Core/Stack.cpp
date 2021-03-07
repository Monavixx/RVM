#include "Stack.h"
#include "../GlobalVariables.h"

void Stack::push(size_t index)
{
	if (stack == nullptr)
		stack = new size_t[maxSize];

	if (currentSize + 1 > maxSize)
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

size_t Stack::popAddress()
{
	if (currentSize <= 0)
		Exit("Stack is empty");
	Object* poppedObject = GlobalVariables::heap[stack[--currentSize]];
	poppedObject->DecAmountUsers();
	return poppedObject->GetAddress();
}

Object* Stack::top()
{
	if (currentSize <= 0)
		Exit("Stack is empty");
	return GlobalVariables::heap[stack[currentSize - 1]];
}

size_t& Stack::topAddress()
{
	if (currentSize <= 0)
		Exit("Stack is empty");
	return stack[currentSize - 1];
}

Stack::~Stack()
{
	delete[] stack;
}
