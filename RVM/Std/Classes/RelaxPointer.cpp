#include "RelaxPointer.h"
#include "../../Core/FieldObject.h"
#include "../../GlobalVariables.h"


RelaxPointer::RelaxPointer(Value* data, const String& dataType) : dataType(dataType)
{
	if (data->valueType == ValueType::OBJECT)
	{
		this->data.isAddress = true;
		this->data.data.address = data->value.object->GetAddress();
	}
	else
	{
		this->data.isAddress = false;
		this->data.data.value = data;
	}
}

RelaxPointer::RelaxPointerData& RelaxPointer::GetData()
{
	return data;
}

void RelaxPointer::SetData(Value* data)
{
	if (Value::GetDataType(data) != dataType)
		Exit("Pointer data type not equal value data type");
	if (data->valueType == ValueType::OBJECT)
	{
		this->data.data.value->value.object = data->value.object;
		this->data.isAddress = true;
	}
	else
	{
		*this->data.data.value = *data;
		this->data.isAddress = false;
	}
}

void RelaxPointer::SetPointerDataType(const String& dataType)
{
	this->dataType = dataType;
}

String RelaxPointer::GetPointerDataType()
{
	return dataType;
}

void RelaxPointer::GenerateMetaInfo()
{
	metaClass = new Class("Relax.Pointer", true);
}
