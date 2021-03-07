#pragma once
#include <vector>
#include "StdMethod.h"

class StdClass
{
public:
	StdClass(const String& name, const std::vector<StdMethod>& methods = {});

	String GetName() const;
	std::vector<StdMethod> GetMethods() const;

	StdMethod* GetMethod(const MethodSignature& signature);
	StdMethod* GetMethod(const String& name, const std::vector<Parameter>& parameters);
	StdMethod* GetMethod(size_t index);

	void AddMethod(const StdMethod& method);

	void SetName(const String& name);
	void SetMethods(const std::vector<StdMethod>& methods);
	void SetMethod(size_t index, const StdMethod& method);
private:
	String name;
	std::vector<StdMethod> methods;
};

