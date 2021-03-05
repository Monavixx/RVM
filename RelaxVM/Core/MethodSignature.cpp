#include "MethodSignature.h"

MethodSignature::MethodSignature(const String& name, const String& dataType, const String& className, const vector<Parameter>& parameters)
	: name(name), dataType(dataType), nameClass(className), parameters(parameters)
{
}

MethodSignature::MethodSignature(const MethodSignature& other)
{
	this->name = other.GetName();
	this->nameClass = other.GetNameClass();
	this->dataType = other.GetDataType();
	this->parameters = other.GetParameters();
}

String MethodSignature::GetName() const
{
	return name;
}

String MethodSignature::GetDataType() const
{
	return dataType;
}

String MethodSignature::GetNameClass() const
{
	return nameClass;
}

const vector<Parameter>& MethodSignature::GetParameters() const
{
	return parameters;
}

Parameter* MethodSignature::GetParameter(size_t index)
{
	return &(parameters[index]);
}

void MethodSignature::SetName(const String& name)
{
	this->name = name;
}

void MethodSignature::SetDataType(const String& dataType)
{
	this->dataType = dataType;
}

void MethodSignature::SetNameClass(const String& className)
{
	this->nameClass = className;
}

void MethodSignature::SetParameters(const vector<Parameter>& parameters)
{
	this->parameters = parameters;
}

void MethodSignature::SetParameter(size_t index, const Parameter& parameter)
{
	parameters[index] = parameter;
}

void MethodSignature::AddParameter(const Parameter& parameter)
{
	parameters.push_back(parameter);
}

String MethodSignature::ToString() const
{
	String signature;
	signature += dataType + " " + nameClass + "." + name + "(";
	for (size_t i = 0; i < parameters.size(); ++i)
	{
		signature += parameters[i].GetDataType();
		if (i != parameters.size() - 1)
			signature += ",";
	}
	signature += ")";
	return signature;
}

bool MethodSignature::operator==(const MethodSignature& other) const
{
	if (other.GetName() != name) return false;
	if (other.GetNameClass() != nameClass) return false;
	if (other.GetParameters() != parameters) return false;
	return  true;
}