#pragma once
#include "DataTypes/Object.h"

class RelaxNull : public Object
{
public:
	String GetDataType() override
	{
		return "Relax.Null";
	}
};