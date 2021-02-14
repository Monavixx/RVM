#pragma once
#include "DataTypes/Object.h"

class RelaxNull : public Object
{
public:
	RelaxNull(const QString& dataType = "") : dataType(dataType)
	{

	}
	QString GetDataType() override
	{
		return dataType;
	}
	QString GetData()
	{
		return "null";
	}
private:
	QString dataType;
};