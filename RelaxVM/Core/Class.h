#pragma once
#include "Method.h"

class Class
{
public:
	Class(const String& name, const vector<Method*>& methods = {});
	~Class();

	String GetName() const;
	vector<Method*> GetMethods() const;
	Method* GetMethod(const String& name, const vector<Parameter>& parameters);
	Method* GetMethod(MethodSignature* signature);

	void SetName(const String& name);
	void SetMethods(const vector<Method*>& methods);
	void SetMethod(int index, Method* method);
	void AddMethod(Method* method);

	bool operator==(const Class& other) const;

private:
	String name;
	vector<Method*> methods;
};

