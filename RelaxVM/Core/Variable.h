#pragma once
#include "../Std/DataTypes/Object.h"

class Variable
{
public:
	Variable(size_t address = 0, const String& dataType = "Relax.Object");

	size_t GetAddress() const;
	void SetAddress(size_t address);

	String GetDataType() const;
	void SetDataType(const String& dataType);

private:
	size_t address;
	String dataType;
};

