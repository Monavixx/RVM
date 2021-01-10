#include "RelaxInt32.h"

RelaxInt32::RelaxInt32(int data) : data(data)
{
}

QString RelaxInt32::GetDataType()
{
    return "Relax.Int32";
}

int RelaxInt32::GetData()
{
    return data;
}

void RelaxInt32::SetData(int data)
{
    this->data = data;
}
