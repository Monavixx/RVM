#include "Variable.h"

Variable::Variable(int address, const QString& dataType) : address(address), dataType(dataType)
{
}

Variable::~Variable()
{
}

int Variable::GetAddress() const
{
	return address;
}

void Variable::SetAddress(int address)
{
	this->address = address;
}

QString Variable::GetDataType() const
{
	return dataType;
}

void Variable::SetDataType(const QString& dataType)
{
	this->dataType = dataType;
}
