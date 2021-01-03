#include "Int32.h"

Int32::Int32(int data) : data(data)
{
}

QString Int32::GetDataType()
{
    return "Relax.Int32";
}

int Int32::GetData()
{
    return data;
}

void Int32::SetData(int data)
{
    this->data = data;
}
