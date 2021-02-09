#pragma once
#include <QtCore>
#include "Method.h"
using std::vector;

class Class
{
public:
	Class(const QString& name, const vector<Method*>& methods = {});
	~Class();

	QString GetName() const;
	vector<Method*> GetMethods() const;
	Method* GetMethod(const QString& name, const vector<Parameter>& parameters);
	Method* GetMethod(MethodSignature* signature);

	void SetName(const QString& name);
	void SetMethods(const vector<Method*>& methods);
	void SetMethod(int index, Method* method);
	void AddMethod(Method* method);

	bool operator==(const Class& other) const;

private:
	QString name;
	vector<Method*> methods;
};

