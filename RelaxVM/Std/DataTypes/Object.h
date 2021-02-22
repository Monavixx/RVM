#pragma once
#include <QtCore>


class Object
{
public:
	Object(int amountUsers = 0);
	virtual QString GetDataType()
	{
		return "Relax.Object";
	}
	virtual ~Object() {}

	void SetAmountUsers(int amountUsers);
	int GetAmountUsers() const;
	void IncAmountUsers();
	void DecAmountUsers();
	void SetAddress(int address);
	int GetAddress() const;

	static void GenerateMetaInfo();
	static inline class StdClass* metaClass = nullptr;
private:
	int amountUsers = 0;
	int address;
};

