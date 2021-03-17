#pragma once
#include "Classes/Object.h"

class RelaxNull : public Object
{
public:
	constexpr String GetDataType() override
	{
		return "Relax.Null"_ss;
	}
};