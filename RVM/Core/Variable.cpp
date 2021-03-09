#include "Variable.h"

Variable::Variable(size_t address, const String& dataType) : address(address), dataType(dataType)
{
}

size_t Variable::GetAddress() const
{
	return address;
}

void Variable::SetAddress(size_t address)
{
	this->address = address;
}

String Variable::GetDataType() const
{
	return dataType;
}

void Variable::SetDataType(const String& dataType)
{
	this->dataType = dataType;
}
