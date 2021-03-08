#include "RelaxFloat.h"
#include "RelaxInt32.h"

RelaxFloat::RelaxFloat(float data) : data(data)
{
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

void RelaxFloat::GenerateMetaInfo()
{
	metaClass = new StdClass("Relax.Float", {
		// operator==
		StdMethod("operator==", "Relax.Bool", "Relax.Float", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			return *thisObject == dynamic_cast<RelaxFloat*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		// operator+
		StdMethod("operator+", "Relax.Float", "Relax.Float", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			return *thisObject + dynamic_cast<RelaxFloat*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		// operator-
		StdMethod("operator-", "Relax.Float", "Relax.Float", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			return *thisObject - dynamic_cast<RelaxFloat*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		// operator*
		StdMethod("operator*", "Relax.Float", "Relax.Float", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			return *thisObject * dynamic_cast<RelaxFloat*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		// operator/
		StdMethod("operator/", "Relax.Float", "Relax.Float", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			return *thisObject / dynamic_cast<RelaxFloat*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		// cast
		StdMethod("cast", "Relax.Float", "Relax.Float", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* data = dynamic_cast<RelaxInt32*>(stack.pop());
			return RelaxFloat::cast(data);
		},AccessModifier::PUBLIC, true),
	});
}
