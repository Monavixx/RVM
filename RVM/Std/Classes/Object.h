#pragma once
#include "../../Libs/String.h"
#include <unordered_map>

struct Value;
struct FieldObject;

class Object
{
public:
	Object(size_t amountUsers = 0);
	constexpr virtual String GetDataType()
	{
		return "Relax.Object"_ss;
	}
	virtual ~Object();

	void CreateFields();

	void SetAmountUsers(size_t amountUsers);
	size_t GetAmountUsers() const;
	void IncAmountUsers();
	void DecAmountUsers();
	void SetAddress(size_t address);
	size_t GetAddress() const;

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;

	std::unordered_map<String, FieldObject*>& GetFields();
	FieldObject* GetField(const String& name);
	void SetField(const String& name, Value* value);
private:
	size_t amountUsers = 0;
	size_t address;

protected:
	std::unordered_map<String, FieldObject*> fields;
};

