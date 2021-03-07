#include "RelaxInt32.h"
#include "RelaxFloat.h"

RelaxInt32::RelaxInt32(int data) : data(data)
{
}

String RelaxInt32::GetDataType()
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

void RelaxInt32::GenerateMetaInfo()
{
    metaClass = new StdClass("Relax.Int32", {
		// operator==
		StdMethod("operator==", "Relax.Bool", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			return *thisObject == dynamic_cast<RelaxInt32*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		// operator+
		StdMethod("operator+", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			return *thisObject + dynamic_cast<RelaxInt32*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		// operator-
		StdMethod("operator-", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			return *thisObject - dynamic_cast<RelaxInt32*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		// operator*
		StdMethod("operator*", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			return *thisObject * dynamic_cast<RelaxInt32*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		// operator/
		StdMethod("operator/", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			return *thisObject / dynamic_cast<RelaxInt32*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		// cast
		StdMethod("cast", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* data = dynamic_cast<RelaxFloat*>(stack.pop());
			return RelaxInt32::cast(data);
		},AccessModifier::PUBLIC, true)
    });
}