#pragma once
#include "Object.h"
#include "../../Functions/Exit.h"

class RelaxConverter : public Object
{
public:
	RelaxConverter() {}
	constexpr String GetDataType() override
	{
		return "Relax.Converter"_ss;
	}

	static int StringToInt32(const String& data);

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;
};

