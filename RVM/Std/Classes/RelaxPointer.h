#pragma once
#include "Object.h"

class RelaxPointer : public Object
{
public:
	RelaxPointer(int pointerAddress, const String& dataType);
	inline String GetDataType() override
	{
		return "Relax.Pointer<"_ss + dataType + ">";
	}
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

