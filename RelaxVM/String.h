#pragma once
#include "Object.h"
class String : public Object
{
public:
	String(const QString& data);
	QString GetDataType() override;
	QString GetData();
	void SetData(const QString& data);
private:
	QString data;
};

