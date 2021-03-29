#include "RelaxArray.h"
#include "../../Core/FieldObject.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"
#include "../../GlobalVariables.h"

RelaxArray::RelaxArray(const String& dataType, asizet size) : dataType(dataType), size(size)
{
	arr = new Value * [size] {nullptr};
}

RelaxArray::~RelaxArray()
{
	delete[] arr;
}

Value** RelaxArray::GetArr()
{
	return arr;
}

void RelaxArray::SetArr(Value** arr)
{
	this->arr = arr;
}

void RelaxArray::SetByIndex(asizet index, Value* value)
{
	if (index >= size)
		Exit("array index out of range");
	if (Value::GetDataType(value) == dataType)
	{
		if(value->valueType == ValueType::OBJECT)
			get<Object*>(value->value)->IncAmountUsers();
		this->arr[index] = value;
	}
}

Value* RelaxArray::GetByIndex(asizet index)
{
	if (index >= size)
		Exit("array index out of range");
	return arr[index];
}

void RelaxArray::GenerateMetaInfo()
{
	metaClass = new Class("Relax.Array", true, {
		new StdMethod("Size", "Relax.Int32", "Relax.Array", {}, [&](Stack& stack) -> Value*
		{
			return new Value(ValueType::INT32, UValue(dynamic_cast<RelaxArray*>(get<Object*>(stack.pop()->value))->GetSize()));
		},AccessModifier::PUBLIC, false),
	});
}
