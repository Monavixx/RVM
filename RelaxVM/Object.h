#pragma once
#include <QtCore>

class Object
{
public:
	Object(int amountUsers = 0);
	virtual QString GetDataType() = 0;
	virtual ~Object() {}
	static int GetSizeDataType();

	void SetAmountUsers(int amountUsers);
	int GetAmountUsers() const;
	void IncAmountUsers();
	void DecAmountUsers();

private:
	int amountUsers = 0;
};

