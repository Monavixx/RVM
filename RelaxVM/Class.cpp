#include "Class.h"

Class::Class(const QString& name, const QList<Method>& methods)
	:name(name), methods(methods)
{
}

QString Class::GetName() const
{
	return name;
}

QList<Method> Class::GetMethods() const
{
	return methods;
}

Method* Class::GetMethod(const QString& name)
{
	auto methodIterator = std::find_if(methods.begin(), methods.end(), [&](const Method& method) {
		return name == method.GetName();
	});
	return nullptr;
}

void Class::SetName(const QString& name)
{
	this->name = name;
}

void Class::SetMethods(const QList<Method>& methods)
{
	this->methods = methods;
}

void Class::SetMethod(const quint64& index, const Method& method)
{
	methods[index] = method;
}

void Class::AddMethod(const Method& method)
{
	methods.push_back(method);
}

bool Class::operator==(const Class& other) const
{
	bool nameIsEqual = other.GetName() == name;
	bool methodsIsEqual = other.GetMethods() == methods;

	return nameIsEqual && methodsIsEqual;
}