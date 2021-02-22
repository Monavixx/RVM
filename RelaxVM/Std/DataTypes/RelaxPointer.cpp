#include "RelaxPointer.h"
#include "../../GlobalVariables.h"


RelaxPointer::RelaxPointer(int pointerAddress, const QString& dataType) : pointerAddress(pointerAddress), dataType(dataType)
{
}

QString RelaxPointer::GetDataType()
{
	return "Relax.Pointer";
}

int RelaxPointer::GetPointerAddress()
{
	return pointerAddress;
}

void RelaxPointer::SetPointerAddress(int pointerAddress)
{
	if (GlobalVariables::heap[pointerAddress]->GetDataType() != dataType)
		Exit("Pointer data type not equal value data type");
	this->pointerAddress = pointerAddress;
}

void RelaxPointer::SetPointerData(Object* data)
{
	if (data->GetDataType() != dataType)
		Exit("Pointer data type not equal value data type");
	GlobalVariables::heap[pointerAddress] = data;
}

Object* RelaxPointer::GetPointerData()
{
	return GlobalVariables::heap[pointerAddress];
}

void RelaxPointer::SetPointerDataType(const QString& dataType)
{
	this->dataType = dataType;
}

QString RelaxPointer::GetPointerDataType()
{
	return dataType;
}
