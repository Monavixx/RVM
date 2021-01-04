#pragma once
#include <QtCore>
#include "Variable.h"

class Stack : public QStack<Variable*>
{
public:
	Stack();
	Stack(const QList<Variable*>& variableList);
	Stack(const Stack& stack);
	~Stack();
};

