#pragma once
#include "../Libs/String.h"

class Parameter
{
public:
	Parameter(const String& dataType, const String& name = "") : dataType(dataType), name(name)
	{
	}

	String GetDataType() const
	{
		return dataType;
	}
	String GetName() const
	{
		return name;
	}

	void SetDataType(const String& dataType)
	{
		this->dataType = dataType;
	}
	void SetName(const String& name)
	{
		this->name = name;
	}

	bool operator==(const Parameter& other) const
	{
		return other.GetDataType() == dataType;
	}
	bool operator!=(const Parameter& other) const
	{
		return other.GetDataType() != dataType;
	}



private:
	String dataType;
	String name;
};

