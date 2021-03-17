#pragma once
#include "Object.h"
#include <random>
#include "RelaxInt32.h"

class RelaxRandom : public Object
{
public:
	RelaxRandom() {}
	constexpr String GetDataType() override
	{
		return "Relax.Random"_ss;
	}
	static RelaxInt32* GenerateInt32();
	static RelaxInt32* GenerateInt32(RelaxInt32* min, RelaxInt32* max);

	static inline std::random_device r;

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;
};

