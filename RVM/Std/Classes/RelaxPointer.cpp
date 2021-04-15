#include "RelaxPointer.h"
#include "../../Core/FieldObject.h"
#include "../../GlobalVariables.h"


RelaxPointer::RelaxPointer(Value* data, const String& dataType) : Object(metaClass), dataType(dataType), data(data)
{
}

Value* RelaxPointer::GetData()
{
	return data;
}

void RelaxPointer::SetData(Value* data)
{
	if (data->valueType == ValueType::OBJECT)
	{
		Object*& old = GlobalVariables::heap[get<size_t>(this->data->value)];
		Object*& newData = GlobalVariables::heap[get<size_t>(data->value)];
		for (auto&[name,field] : newData->GetFields())
		{
			old->SetField(name, field->value);
		}
	}
	else
	{
		this->data->value = data->value;
		this->data->valueType = data->valueType;
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

void RelaxPointer::GenerateMetaClass()
{
	metaClass = new Class("Pointer", true);
}

void RelaxPointer::GenerateMetaMethods()
{
}
