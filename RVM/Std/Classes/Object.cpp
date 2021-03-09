#include "Object.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"

Object::Object(size_t amountUsers) : amountUsers(amountUsers)
{
}

void Object::SetAmountUsers(size_t amountUsers)
{
	this->amountUsers = amountUsers;
}

size_t Object::GetAmountUsers() const
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

void Object::SetAddress(size_t address)
{
	this->address = address;
}

size_t Object::GetAddress() const
{
	return address;
}

void Object::GenerateMetaInfo()
{
	metaClass = new Class("Relax.Object");
}
