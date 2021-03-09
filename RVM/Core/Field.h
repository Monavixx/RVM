#pragma once
#include "../Libs/String.h"
#include "../Enums/AccessModifier.h"

class Field
{
public:
	Field(const String& name, const String& declClassName, const String& dataType = "Relax.Object", AccessModifier accessModifier = AccessModifier::PRIVATE)
		: dataType(dataType), accessModifier(accessModifier), name(name), declClassName(declClassName) {}

	inline size_t GetAddress() const { return address; }
	inline void SetAddress(size_t address) { this->address = address; }

	inline String GetDataType() const { return dataType; }
	inline void SetDataType(const String& dataType) { this->dataType = dataType; }

	inline AccessModifier GetAccessModifier() const { return accessModifier; }
	inline void SetAccessModifier(const AccessModifier& accessModifier) { this->accessModifier = accessModifier; }

	inline String GetName() const { return name; }
	inline void SetName(const String& name) { this->name = name; }

	inline String GetDeclClassName() const { return declClassName; }
	inline void SetDeclClassName(const String& declClassName) { this->declClassName = declClassName; }

private:
	size_t address = 0;
	String dataType;
	AccessModifier accessModifier;
	String name;
	String declClassName;
};

