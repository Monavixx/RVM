#include "Variable.h"

Variable::Variable(int id, Object* data) : id(id), data(data)
{
}

Variable::~Variable()
{
	delete data;
}

int Variable::GetId() const
{
	return this->id;
}

Object* Variable::GetData() const
{
	return this->data;
}

void Variable::SetId(int id)
{
	this->id = id;
}

void Variable::SetData(Object* data)
{
	this->data= data;
}
