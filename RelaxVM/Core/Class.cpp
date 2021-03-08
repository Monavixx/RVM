#include "Class.h"

Class::Class(const String& name, const vector<Method*>& methods)
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

Method* Class::GetMethod(const String& name, const vector<Parameter>& parameters)
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

bool Class::operator==(const Class& other) const
{
	if (other.GetName() != name) return false;
	if (other.GetMethods() != methods) return false;
	return true;
}