#include "Stack.h"

Stack::Stack()
{
}

Stack::Stack(const QList<Variable*>& variableList)
{
	this->clear();
	for (auto& item : variableList)
	{
		this->push_back(item);
	}
}

Stack::Stack(const Stack& stack)
{
	this->clear();
	for (auto& item : stack)
	{
		this->push_back(item);
	}
}

Stack::~Stack()
{
	for (auto& item : *this)
	{
		delete item;
	}
}
