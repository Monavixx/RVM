#include "RelaxArray.h"

RelaxArray::RelaxArray(const QString& dataType, int size) : dataType(dataType), size(size), data(new Object*[size])
{
	for (int i = 0; i < size; ++i)
	{
		data[i] = new RelaxNull;
		data[i]->IncAmountUsers();
	}
}

RelaxArray::~RelaxArray()
{
	delete[] data;
}

QString RelaxArray::GetDataType()
{
	return "Relax.Array";
}

Object** RelaxArray::GetData()
{
	return data;
}

void RelaxArray::SetData(Object** data)
{
	this->data = data;
}

void RelaxArray::SetByIndex(int index, Object* data)
{
	if (data->GetDataType() == dataType)
	{
		data->IncAmountUsers();
		this->data[index] = data;
	}
}

Object* RelaxArray::GetByIndex(int index)
{
	if (index >= size)
		Exit("array index out of range");
	return data[index];
}
