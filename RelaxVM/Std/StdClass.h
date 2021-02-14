#pragma once
#include <QtCore>
#include "StdMethod.h"

class StdClass
{
public:
	StdClass(const QString& name, const QVector<StdMethod>& methods = {});

	QString GetName() const;
	QVector<StdMethod> GetMethods() const;

	StdMethod* GetMethod(const MethodSignature& signature);
	StdMethod* GetMethod(const QString& name, const QVector<Parameter>& parameters);
	StdMethod* GetMethod(int index);

	void SetName(const QString& name);
	void SetMethods(const QVector<StdMethod>& methods);
	void SetMethod(int index, const StdMethod& method);
private:
	QString name;
	QVector<StdMethod> methods;
};

