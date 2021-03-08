#pragma once
#include "Object.h"
#include "RelaxBool.h"

class RelaxString : public Object
{
public:
	RelaxString(const String& data);
	inline String GetDataType() override
	{
		static String dataType = "Relax.String";
		return dataType;
	}
	String GetData();
	void SetData(const String& data);

	RelaxString* Concat(RelaxString* other);

	RelaxString* operator+(RelaxString* other);
	RelaxBool* operator==(RelaxString* other);
	
	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;

private:
	String data;
};

