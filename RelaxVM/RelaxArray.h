#pragma once
#include "Object.h"

class RelaxArray : public Object
{
public:
	RelaxArray(const QString& dataType, int size);
	~RelaxArray();
	QString GetDataType() override;
	Object** GetData();
	void SetData(Object** data);
	void SetByIndex(int index, Object* data);

private:
	QString dataType;
	int size;
	Object** data;
};

