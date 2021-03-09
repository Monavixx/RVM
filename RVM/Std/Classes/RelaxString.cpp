#include "RelaxString.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"

RelaxString::RelaxString(const String& data) : data(data)
{
}

String RelaxString::GetData()
{
    return this->data;
}

void RelaxString::SetData(const String& data)
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

void RelaxString::GenerateMetaInfo()
{
	metaClass = new Class("Relax.String", {
		new StdMethod("Concat", "Relax.String", "Relax.String", {Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			RelaxString* thisObject = dynamic_cast<RelaxString*>(stack.pop());
			return thisObject->Concat(dynamic_cast<RelaxString*>(stack.pop()));
		}, AccessModifier::PUBLIC, false),
		new StdMethod("operator+", "Relax.String", "Relax.String", {Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			RelaxString* thisObject = dynamic_cast<RelaxString*>(stack.pop());
			return *thisObject + dynamic_cast<RelaxString*>(stack.pop());
		}, AccessModifier::PUBLIC, false),
		new StdMethod("operator==", "Relax.Bool", "Relax.String", {Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			RelaxString* thisObject = dynamic_cast<RelaxString*>(stack.pop());
			return *thisObject == dynamic_cast<RelaxString*>(stack.pop());
		}, AccessModifier::PUBLIC, false)
	});
}
