#include "Stack.h"


Stack::Stack() : _size(0)
{
}

void Stack::push(Object*& object)
{
	if (_size > 0)
	{
		Object** newObjects = new Object * [static_cast<quint64>(_size) + 1];
		newObjects[0] = object;
		for (int i = 1; i < _size + 1; ++i)
		{
			newObjects[i] = objects[i - 1];
		}
		delete[] objects;
		objects = newObjects;
	}
	else
	{
		objects = new Object*[1];
		objects[0] = object;
	}
	++_size;
}

Object*& Stack::pop()
{
	if (_size > 0)
	{
		Object** newObjects = new Object* [static_cast<quint64>(_size) - 1];
		Object* object;
		object = objects[0];
		for (int i = 1; i < _size; ++i)
		{
			newObjects[i - 1] = objects[i];
		}
		delete[] objects;
		objects = newObjects;
		--_size;
		return object;
	}
	else
	{
		Exit("Stack::pop(): Empty stack error");
	}
}

int Stack::size() const
{
	return _size;
}

bool Stack::isEmpty() const
{
	return _size < 1;
}
