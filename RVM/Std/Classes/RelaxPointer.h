#pragma once
#include "../../Core/Value.h"
#include "../../Core/Variable.h"

class RelaxPointer : public Object
{
public:
	RelaxPointer(Value* data, const String& dataType);
#ifdef _WIN32
	inline String GetDataType() const override
	{
		return "Pointer<"_ss + dataType + ">";
	}
#else
	virtual inline String GetDataType() const
	{
		static String dataTypePointer = "Pointer<";
		return dataTypePointer + dataType + ">";
	}
#endif
	Value* GetData();
	void SetData(Value* data);
	void SetPointerDataType(const String& dataType);
	String GetPointerDataType();

	static void GenerateMetaMethods();
	static void GenerateMetaClass();
	static inline class Class* metaClass = nullptr;
private:
	
	Value* data;
	String dataType;
};

