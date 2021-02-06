#pragma once
#include <QtCore>
#include "StdMethod.h"

class StdClass
{
public:
	StdClass(const QString& name, const QList<StdMethod>& methods = {});

	QString GetName() const;
	QList<StdMethod> GetMethods() const;

	StdMethod* GetMethod(const MethodSignature& signature);
	StdMethod* GetMethod(const QString& name, const QList<Parameter>& parameters);
	StdMethod* GetMethod(int index);

	void SetName(const QString& name);
	void SetMethods(const QList<StdMethod>& methods);
	void SetMethod(int index, const StdMethod& method);
private:
	QString name;
	QList<StdMethod> methods;
};

