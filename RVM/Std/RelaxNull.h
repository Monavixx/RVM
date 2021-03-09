#pragma once
#include "Classes/Object.h"

class RelaxNull : public Object
{
public:
	String GetDataType() override
	{
		return "Relax.Null";
	}
};