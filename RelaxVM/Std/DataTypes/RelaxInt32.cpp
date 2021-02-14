#include "RelaxInt32.h"
#include "RelaxFloat.h"

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

RelaxBool* RelaxInt32::operator==(RelaxInt32* other)
{
    return new RelaxBool(this->GetData() == other->GetData());
}

RelaxInt32* RelaxInt32::operator+(RelaxInt32* other)
{
	return new RelaxInt32(this->GetData() + other->GetData());
}

RelaxInt32* RelaxInt32::operator-(RelaxInt32* other)
{
    return new RelaxInt32(this->GetData() - other->GetData());
}

RelaxInt32* RelaxInt32::operator*(RelaxInt32* other)
{
    return new RelaxInt32(this->GetData() * other->GetData());
}

RelaxInt32* RelaxInt32::operator/(RelaxInt32* other)
{
    return new RelaxInt32(this->GetData() / other->GetData());
}

RelaxInt32* RelaxInt32::cast(RelaxFloat* data)
{
    return new RelaxInt32(data->GetData());
}
