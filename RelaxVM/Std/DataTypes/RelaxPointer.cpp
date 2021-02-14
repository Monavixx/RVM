#include "RelaxPointer.h"

RelaxPointer::RelaxPointer(Object** data) : data(data)
{
}

QString RelaxPointer::GetDataType()
{
	return "Relax.Pointer";
}

Object** RelaxPointer::GetData()
{
	return data;
}

void RelaxPointer::SetData(Object** data)
{
	this->data = data;
}
