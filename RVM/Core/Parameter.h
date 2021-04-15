#pragma once
#include "../Libs/String.h"

class Parameter
{
public:
	Parameter(const String& namespaceName, const String& dataType, const String& name = "");

	class Class* GetDataType() const;
	String GetName() const
	{
		return name;
	}

	void SetDataType(class Class* dataType);
	
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
	class Class* dataType;
	String name;
};

