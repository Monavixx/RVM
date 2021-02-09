#pragma once
#include <QtCore>
#include "StdMethod.h"

class StdClass
{
public:
	StdClass(const QString& name, const vector<StdMethod>& methods = {});

	QString GetName() const;
	vector<StdMethod>& GetMethods();

	StdMethod* GetMethod(MethodSignature& signature);
	StdMethod* GetMethod(const QString& name, const vector<Parameter>& parameters);
	StdMethod* GetMethod(int index);

	void SetName(const QString& name);
	void SetMethods(const vector<StdMethod>& methods);
	void SetMethod(int index, const StdMethod& method);
private:
	QString name;
	vector<StdMethod> methods;
};

