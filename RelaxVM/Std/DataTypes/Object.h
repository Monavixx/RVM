#pragma once
#include "../../Libs/String.h"

class Object
{
public:
	Object(size_t amountUsers = 0);
	virtual inline String GetDataType()
	{
		static String dataType = "Relax.Object";
		return dataType;
	}
	virtual ~Object() {}

	void SetAmountUsers(size_t amountUsers);
	size_t GetAmountUsers() const;
	void IncAmountUsers();
	void DecAmountUsers();
	void SetAddress(size_t address);
	size_t GetAddress() const;

	static void GenerateMetaInfo();
	static inline class StdClass* metaClass = nullptr;
private:
	size_t amountUsers = 0;
	size_t address;
};

