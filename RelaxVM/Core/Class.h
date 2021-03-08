#pragma once
#include "Method.h"

class Class
{
public:
	Class(const String& name, const vector<Method*>& methods = {});
	~Class();

	inline String GetName() const
	{
		return name;
	}
	vector<Method*> GetMethods() const
	{
		return methods;
	}
	Method* GetMethod(const String& name, const vector<Parameter>& parameters);
	Method* GetMethod(MethodSignature* signature);

	inline void SetName(const String& name)
	{
		this->name = name;
	}

	inline void SetMethods(const vector<Method*>& methods)
	{
		this->methods = methods;
	}
	inline void SetMethod(int index, Method* method)
	{
		methods[index] = method;
	}
	inline void AddMethod(Method* method)
	{
		methods.push_back(method);
	}

	bool operator==(const Class& other) const;

private:
	String name;
	vector<Method*> methods;
};

