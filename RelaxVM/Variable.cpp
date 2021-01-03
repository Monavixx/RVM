#include "Variable.h"

Variable::Variable(const QString& name, Object* data) : name(name), data(data)
{
}

Variable::~Variable()
{
	delete data;
}
