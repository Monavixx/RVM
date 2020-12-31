#include "Parameter.h"

Parameter::Parameter(const QString& name, const QString& dataType) : name(name), dataType(dataType)
{
}

QString Parameter::GetName() const
{
	return name;
}

QString Parameter::GetDataType() const
{
	return dataType;
}

void Parameter::SetName(const QString& name)
{
	this->name = name;
}

void Parameter::SetDataType(const QString& dataType)
{
	this->dataType = dataType;
}

bool Parameter::operator==(const Parameter& other)
{
	bool nameIsEqual = other.GetName() == name;
	bool dataTypeIsEqual = other.GetDataType() == dataType;
	return nameIsEqual && dataTypeIsEqual;
}
