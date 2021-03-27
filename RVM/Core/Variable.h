#pragma once
#include "Value.h"

class Variable
{
public:
	Variable(Value* value = nullptr, const String& dataType = "Relax.Object") : value(value), dataType(dataType)
	{
	}

	inline void SetValue(Value* value)
	{
		this->value = value;
	}
	inline Value* GetValue()
	{
		return value;
	}

	inline String GetDataType() const
	{
		return dataType;
	}
	inline void SetDataType(const String& dataType)
	{
		this->dataType = dataType;
	}

private:
	Value* value;
	String dataType;
};

