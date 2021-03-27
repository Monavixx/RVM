#pragma once
#include "../../Core/Value.h"
#include "../../Core/Variable.h"

class RelaxPointer : public Object
{
	union URelaxPointerData
	{
		Value* value;
		size_t address;
	};
	struct RelaxPointerData
	{
		URelaxPointerData data;
		bool isAddress;
	};
public:
	RelaxPointer(Value* data, const String& dataType);
	inline String GetDataType() override
	{
		return "Relax.Pointer<"_ss + dataType + ">";
	}
	RelaxPointerData& GetData();
	void SetData(Value* data);
	void SetPointerDataType(const String& dataType);
	String GetPointerDataType();

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;
private:
	
	RelaxPointerData data;
	String dataType;
};

