#pragma once
#include "../../Libs/String.h"
#include <unordered_map>

class Object
{
public:
	Object(size_t amountUsers = 0);
	constexpr virtual String GetDataType()
	{
		return "Relax.Object"_ss;
	}
	virtual ~Object() {}
	void CreateFields();

	void SetAmountUsers(size_t amountUsers);
	size_t GetAmountUsers() const;
	void IncAmountUsers();
	void DecAmountUsers();
	void SetAddress(size_t address);
	size_t GetAddress() const;

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;

	struct FieldObject
	{
		size_t address;
		class Field* field;
	};

	std::unordered_map<String, FieldObject>& GetFields();
	FieldObject& GetField(const String& name);
	void SetField(const String& name, size_t address);
private:
	size_t amountUsers = 0;
	size_t address;

protected:
	std::unordered_map<String, FieldObject> fields;
};

