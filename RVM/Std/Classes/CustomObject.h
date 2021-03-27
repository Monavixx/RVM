#pragma once
#include "Object.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"
#include "../../GlobalVariables.h"
#include "../../Core/FieldObject.h"

class CustomObject : public Object
{
public:
	inline CustomObject(Class* declClass) : declClass(declClass)
	{
		for (auto& [name,field] : declClass->GetFields())
		{
			fields[name] = FieldObject{ nullptr, field };
		}
	}

	inline String GetDataType() override
	{
		return declClass->GetName();
	}

	inline void SetDeclClass(Class* declClass) { this->declClass = declClass; }
	inline Class* GetDeclClass() const { return declClass; }

private:
	Class* declClass;
};

