#include "Object.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"
#include "../../GlobalVariables.h"

Object::Object(size_t amountUsers) : amountUsers(amountUsers), address(0)
{
}

void Object::CreateFields()
{
	Class* dataTypeClass = GlobalVariables::classes[GetDataType()];
	for (auto& [name,field] : dataTypeClass->GetFields())
	{
		fields[name] = FieldObject{ GlobalVariables::heap.push_back(new RelaxNull), field };
	}
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

std::unordered_map<String, Object::FieldObject>& Object::GetFields()
{
	return fields;
}

Object::FieldObject& Object::GetField(const String& name)
{
	return fields[name];
}

void Object::SetField(const String& name, size_t address)
{
	fields[name].address = address;
}
