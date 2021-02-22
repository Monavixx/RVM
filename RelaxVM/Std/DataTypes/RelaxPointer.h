#pragma once
#include "Object.h"

class RelaxPointer : public Object
{
public:
	RelaxPointer(int pointerAddress, const QString& dataType);
	QString GetDataType() override;
	int GetPointerAddress();
	void SetPointerAddress(int pointerAddress);
	void SetPointerData(Object* data);
	Object* GetPointerData();
	void SetPointerDataType(const QString& dataType);
	QString GetPointerDataType();
private:
	int pointerAddress;
	QString dataType;
};

