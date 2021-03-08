#pragma once
#include "Object.h"
#include "RelaxInt32.h"
#include "RelaxString.h"
#include "../../Functions/Exit.h"

class RelaxConverter : public Object
{
public:
	RelaxConverter() {}
	inline String GetDataType() override
	{
		static String dataType = "Relax.Converter";
		return dataType;
	}

	static RelaxInt32* StringToInt32(RelaxString* data);
	static RelaxString* Int32ToString(RelaxInt32* data);

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;
};

