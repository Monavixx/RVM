#pragma once
#include "Object.h"

class Variable
{
public:
	Variable(const QString& name, Object* data);
	~Variable();
private:
	Object* data;
	QString name;
};

