#pragma once
#include <QtCore>
#include "Parameter.h"


class MethodSignature
{
public:
	MethodSignature(const QString& name, const QString& dataType, const QString& nameClass, const QList<Parameter>& parameters = {});
	MethodSignature(const MethodSignature& other);

	QString GetName() const;
	QString GetDataType() const;
	QString GetNameClass() const;
	const QList<Parameter>& GetParameters() const;

	Parameter* GetParameter(const QString& name);
	Parameter* GetParameter(const quint64& index);

	void SetName(const QString& name);
	void SetDataType(const QString& dataType);
	void SetNameClass(const QString& nameClass);
	void SetParameters(const QList<Parameter>& parameters);
	void SetParameter(const quint64& index, const Parameter& parameter);
	void AddParameter(const Parameter& parameter);

	QString ToString() const;

	bool operator==(const MethodSignature& other) const;

private:
	QString name;
	QString dataType;
	QString nameClass;
	QList<Parameter> parameters;
};

