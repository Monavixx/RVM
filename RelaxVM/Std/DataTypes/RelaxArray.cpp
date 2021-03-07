#include "RelaxArray.h"
#include "../StdClass.h"
#include "../../GlobalVariables.h"

RelaxArray::RelaxArray(const String& dataType, asizet size) : dataType(dataType), size(size)
{
	arr = new size_t[size];
	for (asizet i = 0; i < size; ++i)
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

String RelaxArray::GetDataType()
{
	return "Relax.Array";
}

size_t* RelaxArray::GetArr()
{
	return arr;
}

void RelaxArray::SetArr(size_t* arr)
{
	this->arr = arr;
}

void RelaxArray::SetByIndex(asizet index, size_t address)
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

int RelaxArray::GetByIndex(asizet index)
{
	if (index >= size)
		Exit("array index out of range");
	return arr[index];
}

void RelaxArray::GenerateMetaInfo()
{
	metaClass = new StdClass("Relax.Array", {
		StdMethod("Size", "Relax.Int32", "Relax.Array", {}, [&](Stack& stack) -> Object*
		{
			return dynamic_cast<RelaxArray*>(stack.pop())->GetSize();
		},AccessModifier::PUBLIC, false),
	});
}
