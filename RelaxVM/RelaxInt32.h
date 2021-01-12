#pragma once
#include "Object.h"

class RelaxInt32 : public Object
{
public:
	RelaxInt32(int data);
	QString GetDataType() override;
	int GetData();
	void SetData(int data);
private:
	int data;
};

