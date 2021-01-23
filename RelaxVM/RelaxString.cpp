#include "RelaxString.h"

RelaxString::RelaxString(const QString& data) : data(data)
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

void RelaxString::SetData(const QString& data)
{
    this->data = data;
}
