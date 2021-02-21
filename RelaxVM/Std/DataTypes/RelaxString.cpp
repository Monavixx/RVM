#include "RelaxString.h"
#include "../StdClass.h"

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

void RelaxString::GenerateMetaInfo()
{
	metaClass = new StdClass("Relax.String", {
		StdMethod("Concat", "Relax.String", "Relax.String", QVector<Parameter>{Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			RelaxString* thisObject = dynamic_cast<RelaxString*>(stack.pop());
			return thisObject->Concat(dynamic_cast<RelaxString*>(stack.pop()));
		}, AccessModifier::PUBLIC, false),
		StdMethod("operator+", "Relax.String", "Relax.String", QVector<Parameter>{Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			RelaxString* thisObject = dynamic_cast<RelaxString*>(stack.pop());
			return *thisObject + dynamic_cast<RelaxString*>(stack.pop());
		}, AccessModifier::PUBLIC, false),
		StdMethod("operator==", "Relax.Bool", "Relax.String", QVector<Parameter>{Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			RelaxString* thisObject = dynamic_cast<RelaxString*>(stack.pop());
			return *thisObject == dynamic_cast<RelaxString*>(stack.pop());
		}, AccessModifier::PUBLIC, false)
	});
}
