#include "RelaxFile.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"
#include "../../GlobalVariables.h"


#ifdef _WIN32
#include <Windows.h>
#endif

String RelaxFile::ReadAll(const String& filename)
{
#ifdef _WIN32
	std::wifstream wif;
	if(filename[1] == ':')
		wif.open(filename.toWCharArray());
	else
		wif.open((GlobalVariables::path + filename).toWCharArray());
	if (!wif.is_open())
		Exit("Relax.File.ReadAll: could not open file", 42);
#pragma warning(suppress : 4996)
	wif.imbue(std::locale(std::locale::empty(), codec));
	std::wstringstream wss;
	wss << wif.rdbuf();
	return wss.str().data();
#else
	std::ifstream fin;
	if (filename[0] == '/')
		fin.open(filename);
	else
		fin.open(GlobalVariables::path + filename);
	if (!fin.is_open())
		Exit("Relax.File.ReadAll: could not open file", 42);
	std::stringstream ss;
	ss << fin.rdbuf();
	return ss.str();
#endif
}
void RelaxFile::GenerateMetaClass()
{
	metaClass = new Class("File", true);
}

void RelaxFile::GenerateMetaMethods()
{
	metaClass->AddMethods({
		new StdMethod("ReadAll", "Relax.String", {Parameter("Relax", "String")}, [&](Stack& stack) -> Value*
		{
			return new Value(ValueType::STR, UValue(ReadAll(get<String>(stack.pop()->value))));
		},AccessModifier::PUBLIC, true)
	});
}
