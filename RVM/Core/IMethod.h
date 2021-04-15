#pragma once
#include "../Enums/AccessModifier.h"
#include "../Libs/String.h"
#include "Parameter.h"
#include <vector>
using std::vector;

class IMethod
{
public:
	inline bool IsStatic() const { return isStatic; }

	inline AccessModifier GetAccessModifier() const { return accessModifier; }

	inline void SetIsStatic(bool isStatic) { this->isStatic = isStatic; }
	inline void SetAccessModifier(const AccessModifier& accessModifier) { this->accessModifier = accessModifier; }

	bool operator==(IMethod& other) const;

	virtual void CallMethod(class Frame* frame) = 0;

	IMethod(const String& name, const String& dataType, const vector<Parameter>& parameters, AccessModifier accessModifier, bool isStatic)
		: name(name), dataType(dataType), parameters(parameters), accessModifier(accessModifier), isStatic(isStatic) {}

	inline String GetName() const { return name; }
	inline String GetDataType() const { return dataType; }
	Class* GetDeclClass() const { return declClass; }
	inline const vector<Parameter>& GetParameters() const { return parameters; }

	inline Parameter* GetParameter(size_t index) { return &(parameters[index]); }

	inline void SetName(const String& name) { this->name = name; }
	inline void SetDataType(const String& dataType) { this->dataType = dataType; }
	void SetDeclClass(Class* declClass) { this->declClass = declClass; }
	inline void SetParameters(const vector<Parameter>& parameters) { this->parameters = parameters; }
	inline void SetParameter(size_t index, const Parameter& parameter) { parameters[index] = parameter; }
	inline void AddParameter(const Parameter& parameter) { parameters.push_back(parameter); }

	bool operator==(const IMethod& other) const;

protected:
	String name;
	String dataType;
	class Class* declClass;
	vector<Parameter> parameters;
	AccessModifier accessModifier;
	bool isStatic;
};

