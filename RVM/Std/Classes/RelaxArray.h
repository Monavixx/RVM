#pragma once
#include "Object.h"
#include "../../Functions/Exit.h"

class RelaxArray : public Object
{
public:
	typedef size_t asizet;

	RelaxArray(const String& dataType, asizet size);
	~RelaxArray();
#ifdef _WIN32
	inline String GetDataType() const override
	{
		return "Array<"_ss + dataType + ">"_ss;
	}
#else
	virtual inline String GetDataType() const
	{
		static String dataTypearr = "Array<";
		return dataTypearr + dataType + ">";
	}
#endif
	Value** GetArr();
	void SetArr(Value** arr);
	void SetByIndex(asizet index, Value* value);
	Value* GetByIndex(asizet index);
	int GetSize() { return size; }


	static void GenerateMetaMethods();
	static void GenerateMetaClass();
	static inline class Class* metaClass = nullptr;

private:
	String dataType;
	asizet size;
	Value** arr;
};

