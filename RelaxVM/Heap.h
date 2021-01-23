#pragma once
#include <QtCore>
#include "Variable.h"

class Heap : public QList<Object*>
{
public: 
	Heap();
	Heap(const QList<Object*>& classList);
	Heap(const Heap& classList);
};

