#pragma once
#include <QtCore>

class Parameter
{
public:
	Parameter(const QString& name, const QString& dataType);
	Parameter(const Parameter& other);

	QString GetName() const;
	QString GetDataType() const;

	void SetName(const QString& name);
	void SetDataType(const QString& dataType);

	bool operator==(const Parameter& other);

private:
	QString name;
	QString dataType;
};

