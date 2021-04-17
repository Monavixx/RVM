#pragma once
#include "IMethod.h"
#include "Field.h"
#include <unordered_map>

class Class
{
public:
	Class(const String& name, bool isStd = false, const vector<IMethod*>& methods = {}, const std::unordered_map<String, Field*>& fields = {});
	~Class();

	inline String GetName() const
	{
		return name;
	}
	inline bool IsStd() const
	{
		return isStd;
	}
	inline vector<IMethod*> GetMethods() const
	{
		return methods;
	}
	inline std::unordered_map<String, Field*>& GetFields() { return fields; }
	IMethod* GetMethod(const String& name, const vector<Parameter>& parameters);
	inline Field* GetField(const String& name) { return fields[name]; }

	inline void SetName(const String& name)
	{
		this->name = name;
	}
	inline void IsStd(bool isStd)
	{
		this->isStd = isStd;
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
		method->SetDeclClass(this);
		methods.push_back(method);
	}
	inline void AddMethods(const vector<IMethod*>& methods)
	{
		for (auto& item : methods)
		{
			item->SetDeclClass(this);
			this->methods.push_back(item);
		}
	}
	inline void AddField(Field* field) { fields[field->GetName()] = field; }

	bool operator==(const Class& other) const;

	void SetNamespace(class Namespace* _namespace);
	Namespace* GetNamespace();

	String GetFullName() const;

	std::unordered_map<String, struct FieldObject*>& GetStaticFields();
	struct FieldObject* GetStaticField(const String& name);
	std::unordered_map<String, struct FieldObject*> GetStaticFields() const;
	void SetStaticFields(const std::unordered_map<String, struct FieldObject*>& staticFields);
	void SetStaticField(const String& name, struct Value* value);

private:
	String name;
	class Namespace* declNamespace;
	vector<IMethod*> methods;
	std::unordered_map<String, Field*> fields;
	std::unordered_map<String, struct FieldObject*> staticFields;
	bool isStd;
};

