#pragma once
#include "Object.h"
#include "RelaxBool.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"

class CustomObject : public Object
{
public:
	inline CustomObject(Class* declClass) :declClass(declClass) {}

	inline String GetDataType() override
	{
		return declClass->GetName();
	}

	inline void SetDeclClass(Class* declClass) { this->declClass = declClass; }
	inline Class* GetDeclClass() const { return declClass; }

private:
	Class* declClass;
};

