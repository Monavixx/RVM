#include "RelaxString.h"

RelaxString::RelaxString(QString data) : data(data)
{
}

QString RelaxString::GetDataType()
{
    return "Relax.String";
}

QString RelaxString::GetData()
{
    return this->data;
}

void RelaxString::SetData(QString data)
{
    this->data = data;
}
