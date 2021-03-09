#pragma once
#include "../Libs/String.h"

class Parameter
{
public:
	Parameter(const String& dataType, const String& name = "");

	String GetDataType() const;
	String GetName() const;

	void SetDataType(const String& dataType);
	void SetName(const String& name);

	bool operator==(const Parameter& other) const;
	bool operator!=(const Parameter& other) const;


private:
	String dataType;
	String name;
};

