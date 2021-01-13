#include "Object.h"

Object::Object(quint64 amountUsers) : amountUsers(amountUsers)
{
}

void Object::SetAmountUsers(quint64 amountUsers)
{
	this->amountUsers = amountUsers;
}

quint64 Object::GetAmountUsers() const
{
	return amountUsers;
}

void Object::IncAmountUsers()
{
	++amountUsers;
}

void Object::DecAmountUsers()
{
	--amountUsers;
}
