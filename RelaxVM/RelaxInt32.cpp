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

RelaxBool* RelaxInt32::operator==(RelaxInt32* other)
{
    bool isEqual = this->GetData() == other->GetData();
    return new RelaxBool(isEqual);
}

RelaxBool* RelaxInt32::operator==(RelaxFloat* other)
{
    bool isEqual = this->GetData() == static_cast<int>(other->GetData());
    return new RelaxBool(isEqual);
}

RelaxInt32* RelaxInt32::operator+(RelaxInt32* other)
{
	int result = this->GetData() + other->GetData();
	return new RelaxInt32(result);
}

RelaxInt32* RelaxInt32::operator-(RelaxInt32* other)
{
    int result = this->GetData() - other->GetData();
    return new RelaxInt32(result);
}

RelaxInt32* RelaxInt32::operator*(RelaxInt32* other)
{
    int result = this->GetData() * other->GetData();
    return new RelaxInt32(result);
}

RelaxInt32* RelaxInt32::operator/(RelaxInt32* other)
{
    int result = this->GetData() / other->GetData();
    return new RelaxInt32(result);
}

RelaxInt32* RelaxInt32::operator+(RelaxFloat* other)
{
    int result = this->GetData() + other->GetData();
    return new RelaxInt32(result);
}

RelaxInt32* RelaxInt32::operator-(RelaxFloat* other)
{
    int result = this->GetData() - other->GetData();
    return new RelaxInt32(result);
}

RelaxInt32* RelaxInt32::operator*(RelaxFloat* other)
{
    int result = this->GetData() * other->GetData();
    return new RelaxInt32(result);
}

RelaxInt32* RelaxInt32::operator/(RelaxFloat* other)
{
    int result = this->GetData() / other->GetData();
    return new RelaxInt32(result);
}
