#pragma once
#include <QtCore>
#include "Method.h"

class Class
{
public:
	Class(const QString& name, const QList<Method*>& methods = {});
	~Class();

	QString GetName() const;
	QList<Method*> GetMethods() const;
	Method* GetMethod(const QString& name, const QList<Parameter>& parameters);
	Method* GetMethod(MethodSignature* signature);

	void SetName(const QString& name);
	void SetMethods(const QList<Method*>& methods);
	void SetMethod(int index, Method* method);
	void AddMethod(Method* method);

	bool operator==(const Class& other) const;

private:
	QString name;
	QList<Method*> methods;
};

