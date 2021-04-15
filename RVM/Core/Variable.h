#pragma once
#include "Value.h"

class Variable
{
public:
	Variable(Value* value = nullptr, class Class* dataType = nullptr) : value(value), dataType(dataType)
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

	String GetDataType() const;
	inline void SetDataType(Class* dataType)
	{
		this->dataType = dataType;
	}

private:
	Value* value;
	class Class* dataType;
};

