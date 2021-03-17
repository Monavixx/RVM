#pragma once
#include "Object.h"
#include "RelaxInt32.h"
#include "RelaxString.h"
#include "../../Functions/Exit.h"

class RelaxConverter : public Object
{
public:
	RelaxConverter() {}
	constexpr String GetDataType() override
	{
		return "Relax.Converter"_ss;
	}

	static RelaxInt32* StringToInt32(RelaxString* data);
	static RelaxString* Int32ToString(RelaxInt32* data);

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;
};

