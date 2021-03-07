#include "StdClass.h"

StdClass::StdClass(const String& name, const std::vector<StdMethod>& methods)
	:name(name), methods(methods)
{

}

String StdClass::GetName() const
{
	return name;
}

std::vector<StdMethod> StdClass::GetMethods() const
{
	return methods;
}

StdMethod* StdClass::GetMethod(const MethodSignature& signature)
{
	auto methodIterator = std::find_if(methods.begin(), methods.end(), [&](const StdMethod& method) {
		return signature == dynamic_cast<const MethodSignature&>(method);
	});
	if(methodIterator == methods.end())
		return nullptr;
	return &(*methodIterator);
}

StdMethod* StdClass::GetMethod(const String& name, const std::vector<Parameter>& parameters)
{
	auto methodIterator = std::find_if(methods.begin(), methods.end(), [&](const StdMethod& method) {
		if (name != method.GetName()) return false;
		if (parameters != method.GetParameters()) return false;
		return true;
	});
	if (methodIterator == methods.end())
		return nullptr;
	return &(*methodIterator);
}

StdMethod* StdClass::GetMethod(size_t index)
{
	if(methods.size() > index)
		return nullptr;
	return &(methods[index]);
}

void StdClass::AddMethod(const StdMethod& method)
{
	methods.push_back(method);
}

void StdClass::SetName(const String& name)
{
	this->name = name;
}

void StdClass::SetMethods(const std::vector<StdMethod>& methods)
{
	this->methods = methods;
}

void StdClass::SetMethod(size_t index, const StdMethod& method)
{
	methods[index] = method;
}
