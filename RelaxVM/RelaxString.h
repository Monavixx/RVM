#pragma once
#include "Object.h"

class RelaxString : public Object
{
public:
	RelaxString(const QString& data);

	QString GetDataType() override;
	QString GetData();

	void SetData(const QString& data);

private:
	QString data;
};

