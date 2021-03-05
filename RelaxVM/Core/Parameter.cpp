#include "Parameter.h"

Parameter::Parameter(const String& dataType, const String& name) : dataType(dataType), name(name)
{
}

String Parameter::GetDataType() const
{
	return dataType;
}

String Parameter::GetName() const
{
	return name;
}


void Parameter::SetDataType(const String& dataType)
{
	this->dataType = dataType;
}

void Parameter::SetName(const String& name)
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
