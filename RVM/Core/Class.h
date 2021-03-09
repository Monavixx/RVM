#pragma once
#include "IMethod.h"
#include "Field.h"
#include <unordered_map>

class Class
{
public:
	Class(const String& name, const vector<IMethod*>& methods = {}, const std::unordered_map<String, Field*>& fields = {});
	~Class();

	inline String GetName() const
	{
		return name;
	}
	inline vector<IMethod*> GetMethods() const
	{
		return methods;
	}
	inline std::unordered_map<String, Field*> GetFields() const { return fields; }
	IMethod* GetMethod(const String& name, const vector<Parameter>& parameters);
	inline Field* GetField(const String& name) { return fields[name]; }

	inline void SetName(const String& name)
	{
		this->name = name;
	}

	inline void SetMethods(const vector<IMethod*>& methods)
	{
		this->methods = methods;
	}
	inline void SetMethod(int index, IMethod* method)
	{
		methods[index] = method;
	}
	inline void AddMethod(IMethod* method)
	{
		methods.push_back(method);
	}
	inline void AddField(Field* field) { fields[field->GetName()] = field; }

	bool operator==(const Class& other) const;

private:
	String name;
	vector<IMethod*> methods;
	std::unordered_map<String, Field*> fields;
};

