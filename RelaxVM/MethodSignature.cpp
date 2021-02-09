#include "MethodSignature.h"

MethodSignature::MethodSignature(const QString& name, const QString& dataType, const QString& className, const vector<Parameter>& parameters)
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

QString MethodSignature::GetName() const
{
	return name;
}

QString MethodSignature::GetDataType() const
{
	return dataType;
}

QString MethodSignature::GetNameClass() const
{
	return nameClass;
}

vector<Parameter> MethodSignature::GetParameters() const
{
	return parameters;
}

Parameter* MethodSignature::GetParameter(const quint64& index)
{
	return &(parameters[index]);
}

void MethodSignature::SetName(const QString& name)
{
	this->name = name;
}

void MethodSignature::SetDataType(const QString& dataType)
{
	this->dataType = dataType;
}

void MethodSignature::SetNameClass(const QString& className)
{
	this->nameClass = className;
}

void MethodSignature::SetParameters(const vector<Parameter>& parameters)
{
	this->parameters = parameters;
}

void MethodSignature::SetParameter(const quint64& index, const Parameter& parameter)
{
	parameters[index] = parameter;
}

void MethodSignature::AddParameter(const Parameter& parameter)
{
	parameters.push_back(parameter);
}

QString MethodSignature::ToString() const
{
	QString signature = "";
	signature += dataType + " " + nameClass + "." + name + "(";
	for (quint64 i = 0; i < parameters.size(); ++i)
	{
		signature += parameters[i].GetDataType();
		if (i != parameters.size() - 1)
			signature += ",";
	}
	signature += ")";
	return signature;
}

bool MethodSignature::operator==(MethodSignature& other)
{
	if (other.GetName() != name) return false;
	if (other.GetNameClass() != nameClass) return false;
	if (other.GetParameters() != parameters) return false;
	return true;
}