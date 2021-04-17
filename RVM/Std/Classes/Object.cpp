#include "Object.h"
#include "../../Core/FieldObject.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"
#include "../../GlobalVariables.h"
#include "../../Core/FieldObject.h"

Object::Object(Class* dataTypeClass) : dataTypeClass(dataTypeClass), address(0) {}

Object::~Object()
{
	for (auto& [name, fo] : fields)
	{
		delete fo;
	}
}

void Object::CreateFields()
{
	for (auto& [name, field] : dataTypeClass->GetFields())
	{
		if(!field->IsStatic())
			fields[name] = new FieldObject{ nullptr, field };
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

void Object::GenerateMetaClass()
{
	metaClass = new Class("Object", true);
}

void Object::GenerateMetaMethods()
{
}

std::unordered_map<String, FieldObject*>& Object::GetFields()
{
	return fields;
}

FieldObject* Object::GetField(const String& name)
{
	return fields[name];
}

void Object::SetField(const String& name, Value* value)
{
	if (!fields.contains(name))
		Exit("field not found");
	if (fields[name]->value != nullptr) delete fields[name]->value;
	fields[name]->value = new Value(value->valueType, value->value);
}
