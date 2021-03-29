#pragma once
#include "Object.h"
#include "../../Libs/ConsoleTextStream.h"
#include "../../Args.h"

class RelaxConsole : public Object
{
public:
	RelaxConsole() {}
#ifdef _WIN321
	constexpr String GetDataType() const override
	{
		return "Relax.Console"_ss;
	}
#else
	virtual inline String GetDataType() const
	{
		static String dataType = "Relax.Console";
		return dataType;
	}
#endif

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;
};

