#pragma once
#include <QtCore>
#include "Class.h"

class ClassList : public QList<Class*>
{
public:
	ClassList();
	ClassList(const QList<Class*>& classList);
	ClassList(const ClassList& classList);

	Class* FindClassByName(const QString& name);
};

