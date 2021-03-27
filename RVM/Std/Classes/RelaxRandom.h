#pragma once
#include "Object.h"
#include <random>

class RelaxRandom : public Object
{
public:
	RelaxRandom() {}
	constexpr String GetDataType() override
	{
		return "Relax.Random"_ss;
	}
	static int GenerateInt32();
	static int GenerateInt32(int min, int max);

	static inline std::random_device r;

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;
};

