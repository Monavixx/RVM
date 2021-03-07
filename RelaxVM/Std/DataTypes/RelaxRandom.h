#pragma once
#include "Object.h"
#include "RelaxInt32.h"

class RelaxRandom : public Object
{
public:
	RelaxRandom() {}
	String GetDataType() override;
	static RelaxInt32* GenerateInt32();
	static RelaxInt32* GenerateInt32(int min, int max);

	static void GenerateMetaInfo();
	static inline class StdClass* metaClass = nullptr;
};

