#include "Parameter.h"

Parameter::Parameter(const QString& dataType, const QString& name) : dataType(dataType), name(name)
{
}

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

bool Parameter::operator==(const Parameter& other) const
{
	return other.GetDataType() == dataType;
}

bool Parameter::operator!=(const Parameter& other) const
{
	return other.GetDataType() != dataType;
}
