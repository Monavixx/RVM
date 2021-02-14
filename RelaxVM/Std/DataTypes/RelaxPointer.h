#pragma once
#include "Object.h"

class RelaxPointer : public Object
{
public:
	RelaxPointer(Object** data);
	QString GetDataType() override;
	Object** GetData();
	void SetData(Object** data);

private:
	Object** data;
};

