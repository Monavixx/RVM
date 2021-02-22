#include "RelaxArray.h"
#include "../StdClass.h"
#include "../../GlobalVariables.h"

RelaxArray::RelaxArray(const QString& dataType, int size) : dataType(dataType), size(size)
{
	arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		Object* data = new RelaxNull;
		data->IncAmountUsers();
		arr[i] = GlobalVariables::heap.push_back(data);
	}
}

RelaxArray::~RelaxArray()
{
	delete[] arr;
}

QString RelaxArray::GetDataType()
{
	return "Relax.Array";
}

int* RelaxArray::GetArr()
{
	return arr;
}

void RelaxArray::SetArr(int* arr)
{
	this->arr = arr;
}

void RelaxArray::SetByIndex(int index, int address)
{
	if (index >= size)
		Exit("array index out of range");
	Object* data = GlobalVariables::heap[address];
	if (data->GetDataType() == dataType)
	{
		data->IncAmountUsers();
		this->arr[index] = address;
	}
}

int RelaxArray::GetByIndex(int index)
{
	if (index >= size)
		Exit("array index out of range");
	return arr[index];
}

void RelaxArray::GenerateMetaInfo()
{
	metaClass = new StdClass("Relax.Array");
}
