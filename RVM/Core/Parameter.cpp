#include "Parameter.h"
#include "Class.h"
#include "../GlobalVariables.h"

Parameter::Parameter(const String& namespaceName, const String& dataType, const String& name) : name(name)
{
	this->dataType = GlobalVariables::namespaces[namespaceName]->GetClass(dataType);
	this->valueType = Value::GetValueType(namespaceName + "." + dataType);
}

Class* Parameter::GetDataType() const
{
	return dataType;
}

void Parameter::SetDataType(Class* dataType, ValueType valueType)
{
	this->dataType = dataType;
}