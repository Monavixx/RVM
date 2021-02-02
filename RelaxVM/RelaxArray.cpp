#include "RelaxArray.h"

RelaxArray::RelaxArray(const QString& dataType, int size) : dataType(dataType), size(size), data(new Object*[size])
{
	for (int i = 0; i < size; ++i)
	{
		//data = new
		data[i]->IncAmountUsers();
	}
}

RelaxArray::~RelaxArray()
{
	for (int i = 0; i < size; ++i)
	{
		delete data[i];
	}
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