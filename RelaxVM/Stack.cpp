#include "Stack.h"

void Stack::push(Object* object)
{
	object->IncAmountUsers();
	QStack::push(object);
}

Object* Stack::pop()
{
	Object* poppedObject = QStack::pop();
	poppedObject->DecAmountUsers();
	return poppedObject;
}
