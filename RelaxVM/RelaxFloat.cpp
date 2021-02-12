#include "RelaxFloat.h"
#include "RelaxInt32.h"

RelaxFloat::RelaxFloat(float data) : data(data)
{
}

QString RelaxFloat::GetDataType()
{
	return "Relax.Float";
}

float RelaxFloat::GetData()
{
	return data;
}

void RelaxFloat::SetData(float data)
{
	this->data = data;
}

RelaxFloat* RelaxFloat::operator+(RelaxFloat* other)
{
	return new RelaxFloat(this->GetData() + other->GetData());
}

RelaxFloat* RelaxFloat::operator-(RelaxFloat* other)
{
	return new RelaxFloat(this->GetData() - other->GetData());
}

RelaxFloat* RelaxFloat::operator*(RelaxFloat* other)
{
	return new RelaxFloat(this->GetData() * other->GetData());
}

RelaxFloat* RelaxFloat::operator/(RelaxFloat* other)
{
	return new RelaxFloat(this->GetData() / other->GetData());
}

RelaxBool* RelaxFloat::operator==(RelaxFloat* other)
{
	return new RelaxBool(this->GetData() == other->GetData());
}

RelaxFloat* RelaxFloat::cast(RelaxInt32* data)
{
	return new RelaxFloat(data->GetData());
}
