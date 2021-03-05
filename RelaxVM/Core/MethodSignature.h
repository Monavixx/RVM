#pragma once
#include "Parameter.h"
#include <vector>
using std::vector;

class MethodSignature
{
public:
	MethodSignature(const String& name, const String& dataType, const String& nameClass, const vector<Parameter>& parameters = {});
	MethodSignature(const MethodSignature& other);

	String GetName() const;
	String GetDataType() const;
	String GetNameClass() const;
	const vector<Parameter>& GetParameters() const;

	Parameter* GetParameter(size_t index);

	void SetName(const String& name);
	void SetDataType(const String& dataType);
	void SetNameClass(const String& nameClass);
	void SetParameters(const vector<Parameter>& parameters);
	void SetParameter(size_t index, const Parameter& parameter);
	void AddParameter(const Parameter& parameter);

	String ToString() const;

	bool operator==(const MethodSignature& other) const;

private:
	String name;
	String dataType;
	String nameClass;
	vector<Parameter> parameters;
};

