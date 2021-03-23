#pragma once
#include "Object.h"
#include "RelaxBool.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"
#include "../../GlobalVariables.h"


class CustomObject : public Object
{
public:
	inline CustomObject(Class* declClass) : declClass(declClass)
	{
		for (auto& [name,field] : declClass->GetFields())
		{
			fields[name] = FieldObject{ GlobalVariables::heap.push_back(new RelaxNull), field };
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

