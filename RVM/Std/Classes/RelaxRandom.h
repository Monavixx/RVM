#pragma once
#include "Object.h"
#include <random>

class RelaxRandom : public Object
{
public:
	RelaxRandom() : Object(metaClass) {}
#ifdef _WIN32
	constexpr String GetDataType() const override
	{
		return "Random"_ss;
	}
#else
	virtual inline String GetDataType() const
	{
		static String dataType = "Random";
		return dataType;
	}
#endif
	static int GenerateInt32();
	static int GenerateInt32(int min, int max);

	static inline std::random_device r;

	static void GenerateMetaClass();
	static void GenerateMetaMethods();
	static inline class Class* metaClass = nullptr;
};

