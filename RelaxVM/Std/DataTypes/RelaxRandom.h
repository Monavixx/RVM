#pragma once
#include "Object.h"
#include "RelaxInt32.h"

class RelaxRandom : public Object
{
public:
	RelaxRandom() {}
	inline String GetDataType() override
	{
		static String dataType = "Relax.Random";
		return dataType;
	}
	static RelaxInt32* GenerateInt32();
	static RelaxInt32* GenerateInt32(RelaxInt32* min, RelaxInt32* max);

	static void GenerateMetaInfo();
	static inline class StdClass* metaClass = nullptr;
};

