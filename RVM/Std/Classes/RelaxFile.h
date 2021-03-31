#pragma once
#include "Object.h"
#include <codecvt>
#include <fstream>
#include <sstream>

class RelaxFile : public Object
{
public:
	RelaxFile() {}
#ifdef _WIN32
	constexpr String GetDataType() const override
	{
		return "Relax.File"_ss;
	}
#else
	virtual inline String GetDataType() const
	{
		static String dataType = "Relax.File";
		return dataType;
	}
#endif
	static String ReadAll(const String& filename);
#ifdef _WIN32
	#pragma warning(suppress : 4996)
	static inline std::codecvt_utf8<wchar_t>* codec = new std::codecvt_utf8<wchar_t>;
#endif
	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;
};

