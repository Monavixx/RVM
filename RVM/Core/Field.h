#pragma once
#include "../Libs/String.h"
#include "../Enums/AccessModifier.h"

class Field
{
public:
	Field(AccessModifier accessModifier, bool isStatic, const String& dataType, const String& declClassName, const String& name)
		: dataType(dataType), accessModifier(accessModifier), name(name), declClassName(declClassName), isStatic(isStatic) {}

	inline String GetDataType() const { return dataType; }
	inline void SetDataType(const String& dataType) { this->dataType = dataType; }

	inline AccessModifier GetAccessModifier() const { return accessModifier; }
	inline void SetAccessModifier(const AccessModifier& accessModifier) { this->accessModifier = accessModifier; }

	inline String GetName() const { return name; }
	inline void SetName(const String& name) { this->name = name; }

	inline String GetDeclClassName() const { return declClassName; }
	inline void SetDeclClassName(const String& declClassName) { this->declClassName = declClassName; }

	inline bool IsStatic() const { return isStatic; }
	inline void IsStatic(bool isStatic) { this->isStatic = isStatic; }
private:
	String dataType;
	AccessModifier accessModifier;
	bool isStatic;
	String name;
	String declClassName;
};

