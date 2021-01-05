#pragma once
#include <QtCore>
#include "Variable.h"

class Stack : public QStack<Object*>
{
public:
	Stack();
	Stack(const QList<Object*>& variableList);
	Stack(const Stack& stack);
	~Stack();
};

