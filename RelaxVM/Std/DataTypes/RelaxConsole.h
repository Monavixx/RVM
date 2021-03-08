#pragma once
#include "Object.h"
#include "RelaxString.h"
#include "RelaxInt32.h"
#include "RelaxFloat.h"
#include "RelaxBool.h"
#include "../RelaxNull.h"
#include "../../Libs/ConsoleTextStream.h"
#include "../../Args.h"

class RelaxConsole : public Object
{
public:
	RelaxConsole() {}
	inline String GetDataType() override
	{
		static String dataType = "Relax.Console";
		return dataType;
	}

	static Object* Write(RelaxString* data);
	static Object* Write(RelaxInt32* data);
	static Object* Write(RelaxFloat* data);
	static Object* Write(RelaxBool* data);

	static Object* Print(RelaxString* data);
	static Object* Print(RelaxInt32* data);
	static Object* Print(RelaxFloat* data);
	static Object* Print(RelaxBool* data);

	static RelaxString* Read();

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;
};

