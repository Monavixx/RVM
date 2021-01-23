#pragma once
#include <QtCore>

class Parameter
{
public:
	Parameter(const QString& dataType);
	//Parameter(const Parameter& other);

	QString GetDataType() const;

	void SetDataType(const QString& dataType);

	bool operator==(const Parameter& other);

private:
	QString dataType;
};

