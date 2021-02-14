#pragma once
#include "Object.h"

class RelaxBool : public Object
{
public:
	RelaxBool(bool data);
	QString GetDataType() override;
	bool GetData();
	void SetData(bool data);
private:
	bool data;
};

