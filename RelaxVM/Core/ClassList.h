#pragma once
#include <QtCore>
#include "Class.h"

class ClassList : public QVector<Class*>
{
public:
	ClassList();
	ClassList(const QVector<Class*>& classList);
	ClassList(const ClassList& classList);

	Class* FindClassByName(const QString& name);
};

