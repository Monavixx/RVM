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
#ifdef _WIN32
	inline String GetDataType() const override
	{
		return "Relax.Pointer<"_ss + dataType + ">";
	}
#else
	virtual inline String GetDataType() const
	{
		static String dataTypePointer = "Relax.Pointer<";
		return dataTypePointer + dataType + ">";
	}
#endif
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

