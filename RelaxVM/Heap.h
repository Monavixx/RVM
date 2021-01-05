#pragma once
#include <QtCore>
#include "Variable.h"

class Heap : public QList<Variable*>
{
public: 
	Heap();
	Heap(const QList<Variable*>& classList);
	Heap(const Heap& classList);


	Variable* FindVariableById(int id);
};

