#pragma once
#include "Method.h"
#include "Field.h"
#include <unordered_map>

class Class
{
public:
	Class(const String& name, const vector<Method*>& methods = {}, const std::unordered_map<String, Field*>& fields = {});
	~Class();

	inline String GetName() const
	{
		return name;
	}
	inline vector<Method*> GetMethods() const
	{
		return methods;
	}
	inline std::unordered_map<String, Field*> GetFields() const { return fields; }
	Method* GetMethod(const String& name, const vector<Parameter>& parameters);
	Method* GetMethod(MethodSignature* signature);
	inline Field* GetField(const String& name) { return fields[name]; }

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
	inline void AddField(Field* field) { fields[field->GetName()] = field; }

	bool operator==(const Class& other) const;

private:
	String name;
	vector<Method*> methods;
	std::unordered_map<String, Field*> fields;
};

