#pragma once
#include "Object.h"

class RelaxFloat : public Object
{
public:
	RelaxFloat(float data);
	QString GetDataType() override;
	float GetData();
	void SetData(float data);
private:
	float data;
};

