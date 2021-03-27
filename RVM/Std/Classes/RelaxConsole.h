#pragma once
#include "Object.h"
#include "../../Libs/ConsoleTextStream.h"
#include "../../Args.h"

class RelaxConsole : public Object
{
public:
	RelaxConsole() {}
	constexpr String GetDataType() override
	{
		return "Relax.Console"_ss;
	}

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;
};

