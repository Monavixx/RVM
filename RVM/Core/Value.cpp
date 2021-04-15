#include "Value.h"
#include "FieldObject.h"
#include "../GlobalVariables.h"

ValueType Value::GetValueType(const String& dataType)
{
	static std::unordered_map<String, ValueType> dataTypes = {
		{"Relax.Int32", ValueType::INT32},
		{"Relax.Float", ValueType::FLOAT},
		{"Relax.String", ValueType::STR},
		{"void", ValueType::_VOID},
		{"Relax.Bool", ValueType::BOOL}
	};

	if (dataTypes.contains(dataType))
	{
		return dataTypes[dataType];
	}
	else
	{
		return ValueType::OBJECT;
	}
}

String Value::GetDataType(Value* value)
{
	static std::unordered_map<ValueType, String> dataTypes = {
		{ValueType::INT32, "Relax.Int32"},
		{ValueType::FLOAT, "Relax.Float"},
		{ValueType::STR, "Relax.String"},
		{ValueType::_VOID, "void"},
		{ValueType::BOOL, "Relax.Bool"}
	};

	if (value == nullptr)
		return "Relax.Null";
	if (value->valueType == ValueType::OBJECT)
	{
		return GlobalVariables::heap[get<size_t>(value->value)]->GetDataTypeClass()->GetFullName();
	}
	else
	{
		return dataTypes[value->valueType];
	}
}