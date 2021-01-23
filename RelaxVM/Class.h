#pragma once
#include <QtCore>
#include "Method.h"

class Class
{
public:
	Class(const QString& name, const QList<Method>& methods = {});

	QString GetName() const;
	QList<Method> GetMethods() const;
	Method* GetMethod(const QString& name, const QString& dataType, const QList<Parameter>& parameters);
	Method* GetMethod(const MethodSignature& signature);

	void SetName(const QString& name);
	void SetMethods(const QList<Method>& methods);
	void SetMethod(int index, const Method& method);
	void AddMethod(const Method& method);

	bool operator==(const Class& other) const;

private:
	QString name;
	QList<Method> methods;
};

