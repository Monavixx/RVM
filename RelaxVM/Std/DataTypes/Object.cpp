#include "Object.h"
#include "../StdClass.h"

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

void Object::SetAddress(int address)
{
	this->address = address;
}

int Object::GetAddress() const
{
	return address;
}

void Object::GenerateMetaInfo()
{
	metaClass = new StdClass("Relax.Object");
}
