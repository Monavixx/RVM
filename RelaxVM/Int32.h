#pragma once
#include "Object.h"
class Int32 : public Object
{
public:
	Int32(int data);
	QString GetDataType() override;
	int GetData();
	void SetData(int data);
private:
	int data;
};

