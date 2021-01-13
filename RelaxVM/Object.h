#pragma once
#include <QtCore>

class Object
{
public:
	Object(quint64 amountUsers = 0);
	virtual QString GetDataType() = 0;

	void SetAmountUsers(quint64 amountUsers);
	quint64 GetAmountUsers() const;
	void IncAmountUsers();
	void DecAmountUsers();

private:
	quint64 amountUsers = 0;
};

