#include "Class.h"

Class::Class(const QString& name, const QVector<Method*>& methods)
	:name(name), methods(methods)
{
}

Class::~Class()
{
	for (auto& item : methods)
	{
		delete item;
	}
}

QString Class::GetName() const
{
	return name;
}

QVector<Method*> Class::GetMethods() const
{
	return methods;
}

Method* Class::GetMethod(const QString& name, const QVector<Parameter>& parameters)
{
	auto methodIterator = std::find_if(methods.begin(), methods.end(), [&](Method* method) {
		if (name != method->GetName()) return false;
		if (parameters != method->GetParameters()) return false;
		return true;
	});
	if(methodIterator == methods.end())
		return nullptr;
	return *methodIterator;
}

Method* Class::GetMethod(MethodSignature* signature)
{
	auto methodIterator = std::find_if(methods.begin(), methods.end(), [&](Method* method) {
		return signature == dynamic_cast<MethodSignature*>(method);
	});
	if (methodIterator == methods.end())
		return nullptr;
	return *methodIterator;
}

void Class::SetName(const QString& name)
{
	this->name = name;
}

void Class::SetMethods(const QVector<Method*>& methods)
{
	this->methods = methods;
}

void Class::SetMethod(int index, Method* method)
{
	methods[index] = method;
}

void Class::AddMethod(Method* method)
{
	methods.push_back(method);
}

bool Class::operator==(const Class& other) const
{
	if (other.GetName() != name) return false;
	if (other.GetMethods() != methods) return false;
	return true;
}