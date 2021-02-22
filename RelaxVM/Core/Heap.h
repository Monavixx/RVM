#pragma once
#include <QtCore>
#include "Variable.h"

class Heap : public QVector<Object*>
{
public: 
	Heap();
	Heap(const QVector<Object*>& classList);
	Heap(const Heap& classList);

	int push_back(Object* const &data)
	{
		data->SetAddress(size());
		QVector<Object*>::push_back(data);
		return size() - 1;
	}
};

