#pragma once
#include "../../Libs/String.h"
#include <unordered_map>

using namespace std;

struct Value;
struct FieldObject;

class Object
{
public:
	Object(size_t amountUsers = 0);
#ifdef _WIN32
	constexpr virtual String GetDataType() const
	{
		return "Relax.Object"_ss;
	}
#else
	virtual inline String GetDataType() const
	{
		static String dataType = "Relax.Object";
		return dataType;
	}
#endif
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

