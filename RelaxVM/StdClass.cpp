#include "StdClass.h"

StdClass::StdClass(const QString& name, const vector<StdMethod>& methods)
	:name(name), methods(methods)
{

}

QString StdClass::GetName() const
{
	return name;
}

vector<StdMethod>& StdClass::GetMethods()
{
	return methods;
}

StdMethod* StdClass::GetMethod(MethodSignature& signature)
{
	auto methodIterator = std::find_if(methods.begin(), methods.end(), [&](StdMethod& method) {
		return signature == dynamic_cast<MethodSignature&>(method);
	});
	if(methodIterator == methods.end())
		return nullptr;
	return &(*methodIterator);
}

StdMethod* StdClass::GetMethod(const QString& name, const vector<Parameter>& parameters)
{
	auto methodIterator = std::find_if(methods.begin(), methods.end(), [&](StdMethod& method) {
		if (name != method.GetName()) return false;
		if (parameters != method.GetParameters()) return false;
		return true;
	});
	if (methodIterator == methods.end())
		return nullptr;
	return &(*methodIterator);
}

StdMethod* StdClass::GetMethod(int index)
{
	if(methods.size() > index)
		return nullptr;
	return &(methods[index]);
}

void StdClass::SetName(const QString& name)
{
	this->name = name;
}

void StdClass::SetMethods(const vector<StdMethod>& methods)
{
	this->methods = methods;
}

void StdClass::SetMethod(int index, const StdMethod& method)
{
	methods[index] = method;
}
