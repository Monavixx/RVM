#include "Stack.h"
#include "../GlobalVariables.h"
#include "FieldObject.h"

void Stack::push(Value* value)
{
	if (stack == nullptr)
		stack = new Value*[maxSize];

	if (currentSize + 1 > maxSize)
		Exit("Stack is small");

	if(value->valueType == ValueType::OBJECT && value->value.object != nullptr)
		value->value.object->IncAmountUsers();
	
	stack[currentSize++] = value;
}

Value* Stack::pop()
{
	if (currentSize <= 0)
		Exit("Stack is empty");
	Value* value = stack[--currentSize];
	if(value->valueType == ValueType::OBJECT)
		value->value.object->DecAmountUsers();
	return value;
}


Value* Stack::top()
{
	if (currentSize <= 0)
		Exit("Stack is empty");
	return stack[currentSize - 1];
}

Stack::~Stack()
{
	delete[] stack;
}
