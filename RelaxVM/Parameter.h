#pragma once
#include <QtCore>

class Parameter
{
public:
	Parameter(const QString& dataType, const QString& name = "");

	QString GetDataType() const;
	QString GetName() const;

	void SetDataType(const QString& dataType);
	void SetName(const QString& name);

	bool operator==(const Parameter& other);

private:
	QString dataType;
	QString name;
};

