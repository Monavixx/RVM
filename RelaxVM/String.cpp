#include "String.h"

String::String(const QString& data) : data(data)
{
	
}

QString String::GetDataType()
{
	return "Relax.String";
}

QString String::GetData()
{
	return this->data;
}

void String::SetData(const QString& data)
{
	this->data = data;
}
