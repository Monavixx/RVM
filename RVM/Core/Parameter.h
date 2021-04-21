#pragma once
#include "../Libs/String.h"
#include "Value.h"

class Parameter
{
public:
	Parameter(const String& namespaceName, const String& dataType, const String& name = "");

	class Class* GetDataType() const;
	inline ValueType GetValueType() const
	{
		return valueType;
	}
	inline String GetName() const
	{
		return name;
	}

	void SetDataType(class Class* dataType, ValueType valueType = ValueType::OBJECT);
	
	inline void SetName(const String& name)
	{
		this->name = name;
	}

	inline bool operator==(const Parameter& other) const
	{
		return ((other.dataType == dataType) && dataType != nullptr) || (other.valueType == valueType);
	}
	inline bool operator!=(const Parameter& other) const
	{
		return ((other.dataType != dataType) && dataType != nullptr) && (other.valueType != valueType);
	}

private:
	class Class* dataType;
	String name;
	ValueType valueType;
};

