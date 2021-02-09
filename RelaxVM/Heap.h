#pragma once
#include <QtCore>
#include "Variable.h"
using std::list;

class Heap : public list<Object*>
{
public: 
	Heap();
	Heap(const list<Object*>& classList);
	Heap(const Heap& classList);
};

