#include "MethodSignature.h"

MethodSignature::MethodSignature(const QString& name, const QString& dataType, const QString& className, const QList<Parameter>& parameters)
	: name(name), dataType(dataType), nameClass(className), parameters(parameters)
{
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

const QList<Parameter>& MethodSignature::GetParameters() const
{
	return parameters;
}

Parameter* MethodSignature::GetParameter(const QString& name)
{
	auto parameterIterator = std::find_if(parameters.begin(), parameters.end(), [&](Parameter& parameter) {
		return parameter.GetName() == name;
	});
	if(parameterIterator == parameters.end())
		return nullptr;
	return &(*parameterIterator);
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

void MethodSignature::SetParameters(const QList<Parameter>& parameters)
{
	this->parameters = parameters;
}

void MethodSignature::SetParameter(const quint64& index, const Parameter& parameter)
{
	parameters[index] = parameter;
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
