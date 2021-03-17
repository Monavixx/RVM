#pragma once
#include "Object.h"
#include "../../Functions/Exit.h"
#include "../RelaxNull.h"
#include "RelaxInt32.h"

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
	size_t* GetArr();
	void SetArr(size_t* arr);
	void SetByIndex(asizet index, size_t address);
	size_t GetByIndex(asizet index);
	RelaxInt32* GetSize() { return new RelaxInt32(size); }


	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;

private:
	String dataType;
	asizet size;
	size_t* arr;
};

