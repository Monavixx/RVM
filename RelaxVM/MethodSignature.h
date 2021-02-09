#pragma once
#include <QtCore>
#include "Parameter.h"
using std::vector;


class MethodSignature
{
public:
	MethodSignature(const QString& name, const QString& dataType, const QString& nameClass, const vector<Parameter>& parameters = {});
	MethodSignature(const MethodSignature& other);

	QString GetName() const;
	QString GetDataType() const;
	QString GetNameClass() const;
	vector<Parameter> GetParameters() const;

	Parameter* GetParameter(const quint64& index);

	void SetName(const QString& name);
	void SetDataType(const QString& dataType);
	void SetNameClass(const QString& nameClass);
	void SetParameters(const vector<Parameter>& parameters);
	void SetParameter(const quint64& index, const Parameter& parameter);
	void AddParameter(const Parameter& parameter);

	QString ToString() const;

	bool operator==(MethodSignature& other);

private:
	QString name;
	QString dataType;
	QString nameClass;
	vector<Parameter> parameters;
};