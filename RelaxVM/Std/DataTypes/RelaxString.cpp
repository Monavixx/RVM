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

RelaxString* RelaxString::Concat(RelaxString* other)
{
    return new RelaxString(this->GetData() + other->GetData());
}

RelaxString* RelaxString::operator+(RelaxString* other)
{
    return Concat(other);
}

RelaxBool* RelaxString::operator==(RelaxString* other)
{
    return new RelaxBool(this->GetData() == other->GetData());
}
