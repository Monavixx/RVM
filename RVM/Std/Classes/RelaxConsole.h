#pragma once
#include "Object.h"
#include "../../Libs/ConsoleTextStream.h"
#include "../../Args.h"

class RelaxConsole : public Object
{
public:
	RelaxConsole():Object(metaClass) {}
#ifdef _WIN32
	constexpr String GetDataType() const override
	{
		return "Console"_ss;
	}
#else
	virtual inline String GetDataType() const
	{
		static String dataType = "Console";
		return dataType;
	}
#endif

	static void GenerateMetaMethods();
	static void GenerateMetaClass();
	static inline class Class* metaClass;
};

