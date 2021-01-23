#include "Object.h"

Object::Object(int amountUsers) : amountUsers(amountUsers)
{
}

void Object::SetAmountUsers(int amountUsers)
{
	this->amountUsers = amountUsers;
}

int Object::GetAmountUsers() const
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
