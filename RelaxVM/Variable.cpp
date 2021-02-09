#include "Variable.h"

Variable::Variable(Object* data) : data(data)
{
}

Variable::~Variable()
{
}

Object* Variable::GetData() const
{
	return this->data;
}

void Variable::SetData(Object* data)
{
	this->data= data;
}
