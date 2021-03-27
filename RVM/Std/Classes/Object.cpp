#include "Object.h"
#include "../../Core/FieldObject.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"
#include "../../GlobalVariables.h"
#include "../../Core/FieldObject.h"

Object::Object(size_t amountUsers) : amountUsers(amountUsers), address(0)
{
}

void Object::CreateFields()
{
	Class* dataTypeClass = GlobalVariables::classes[GetDataType()];
	for (auto& [name, field] : dataTypeClass->GetFields())
	{
		fields[name] = FieldObject{ nullptr, field };
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
	metaClass = new Class("Relax.Object", true);
}

std::unordered_map<String, FieldObject>& Object::GetFields()
{
	return fields;
}

FieldObject& Object::GetField(const String& name)
{
	return fields[name];
}

void Object::SetField(const String& name, Value* value)
{
	if (!fields.contains(name))
		Exit("field not found");
	fields[name].value = value;
}
