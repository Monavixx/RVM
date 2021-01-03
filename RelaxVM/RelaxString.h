#pragma once
#include "Object.h"
class RelaxString : public Object
{
public:
	RelaxString(QString data);
	QString GetDataType() override;
	QString GetData();
	void SetData(QString data);
private:
	QString data;
};

