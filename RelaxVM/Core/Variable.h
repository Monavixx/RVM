#pragma once
#include "../Std/DataTypes/Object.h"

class Variable
{
public:
	Variable(int address = 0, const QString& dataType = "Relax.Null");
	~Variable();

	int GetAddress() const;
	void SetAddress(int address);

	QString GetDataType() const;
	void SetDataType(const QString& dataType);

private:
	int address;
	QString dataType;
};

