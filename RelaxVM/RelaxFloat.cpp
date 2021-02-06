#include "RelaxFloat.h"

RelaxFloat::RelaxFloat(float data) : data(data)
{
}

QString RelaxFloat::GetDataType()
{
	return "Relax.Float";
}

float RelaxFloat::GetData()
{
	return data;
}

void RelaxFloat::SetData(float data)
{
	this->data = data;
}
