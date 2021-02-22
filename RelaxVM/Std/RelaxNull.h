#pragma once
#include "DataTypes/Object.h"

class RelaxNull : public Object
{
public:
	RelaxNull()
	{

	}
	QString GetDataType() override
	{
		return "Relax.Null";
	}
};