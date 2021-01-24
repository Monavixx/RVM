#include "Parameter.h"

Parameter::Parameter(const QString& dataType) : dataType(dataType)
{
}
/*
Parameter::Parameter(const Parameter& other)
{
	this->dataType = other.GetDataType();
}
*/

QString Parameter::GetDataType() const
{
	return dataType;
}

QString Parameter::GetName() const
{
	return name;
}


void Parameter::SetDataType(const QString& dataType)
{
	this->dataType = dataType;
}

void Parameter::SetName(const QString& name)
{
	this->name = name;
}

bool Parameter::operator==(const Parameter& other)
{
	bool dataTypeIsEqual = other.GetDataType() == dataType;
	return dataTypeIsEqual;
}
