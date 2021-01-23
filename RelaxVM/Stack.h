#pragma once
#include <QtCore>
#include "Object.h"


class Stack : public QStack<Object*>
{
public:
	void push(Object* object);
	Object* pop();
};

