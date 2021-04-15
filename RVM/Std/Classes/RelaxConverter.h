#pragma once
#include "Object.h"
#include "../../Functions/Exit.h"

class RelaxConverter : public Object
{
public:
	RelaxConverter() :Object(metaClass) {}
#ifdef _WIN32
	constexpr String GetDataType() const override
	{
		return "Converter"_ss;
	}
#else
	virtual inline String GetDataType() const
	{
		static String dataType = "Converter";
		return dataType;
	}
#endif

	static int ToInt32(const String& data);
	static float ToFloat(const String& data);

	static void GenerateMetaMethods();
	static void GenerateMetaClass();
	static inline class Class* metaClass = nullptr;
};

