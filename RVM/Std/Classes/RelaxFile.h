#pragma once
#include "Object.h"
#include <codecvt>
#include <fstream>
#include <sstream>

class RelaxFile : public Object
{
public:
	RelaxFile(): Object(metaClass) {}
#ifdef _WIN32
	constexpr String GetDataType() const override
	{
		return "File"_ss;
	}
#else
	virtual inline String GetDataType() const
	{
		static String dataType = "File";
		return dataType;
	}
#endif
	static String ReadAll(const String& filename);
#ifdef _WIN32
	#pragma warning(suppress : 4996)
	static inline std::codecvt_utf8<wchar_t>* codec = new std::codecvt_utf8<wchar_t>;
#endif
	static void GenerateMetaMethods();
	static void GenerateMetaClass();
	static inline class Class* metaClass = nullptr;
};

