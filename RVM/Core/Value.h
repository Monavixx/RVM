#pragma once
#include "../Std/Classes/Object.h"
#include "../Libs/String.h"
#include <unordered_map>

union UValue
{
	Object* object;
	String str;
	int inum;
	float fnum;
	bool boolean;
};
enum class ValueType
{
	OBJECT,
	STR,
	INT32,
	FLOAT,
	_VOID,
	BOOL
};
struct Value
{
	Value(ValueType valueType = ValueType::_VOID, UValue value = {}) : valueType(valueType), value(value)
	{
	}

	ValueType valueType;
	UValue value;

	static ValueType GetValueType(const String& dataType);

	static String GetDataType(Value* value);
	
};