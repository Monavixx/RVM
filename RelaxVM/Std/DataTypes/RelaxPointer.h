#pragma once
#include "Object.h"

class RelaxPointer : public Object
{
public:
	RelaxPointer(int pointerAddress, const String& dataType);
	String GetDataType() override;
	int GetPointerAddress();
	void SetPointerAddress(int pointerAddress);
	void SetPointerData(Object* data);
	Object* GetPointerData();
	void SetPointerDataType(const String& dataType);
	String GetPointerDataType();
private:
	int pointerAddress;
	String dataType;
};

