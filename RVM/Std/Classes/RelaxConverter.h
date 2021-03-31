#pragma once
#include "Object.h"
#include "../../Functions/Exit.h"

class RelaxConverter : public Object
{
public:
	RelaxConverter() {}
#ifdef _WIN32
	constexpr String GetDataType() const override
	{
		return "Relax.Converter"_ss;
	}
#else
	virtual inline String GetDataType() const
	{
		static String dataType = "Relax.Converter";
		return dataType;
	}
#endif

	static int ToInt32(const String& data);
	static float ToFloat(const String& data);

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;
};

