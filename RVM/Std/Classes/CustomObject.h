#pragma once
#include "Object.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"
#include "../../GlobalVariables.h"
#include "../../Core/FieldObject.h"

class CustomObject : public Object
{
public:
	inline CustomObject(Class* dataTypeClass) : Object(dataTypeClass)
	{
		CreateFields();
	}

	inline String GetDataType() const override
	{
		return dataTypeClass->GetName();
	}
};

