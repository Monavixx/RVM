#pragma once
#include "Object.h"
#include "../../Functions/Exit.h"

class RelaxArray : public Object
{
public:
	typedef size_t asizet;

	RelaxArray(const String& dataType, asizet size);
	~RelaxArray();
	inline String GetDataType() override
	{
		return "Relax.Array<"_ss + dataType + ">"_ss;
	}
	Value** GetArr();
	void SetArr(Value** arr);
	void SetByIndex(asizet index, Value* value);
	Value* GetByIndex(asizet index);
	int GetSize() { return size; }


	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;

private:
	String dataType;
	asizet size;
	Value** arr;
};

