#include "OpField.h"
#include "../Core/FieldObject.h"

void OpField::Run()
{
	Namespace* declNamespace = GlobalVariables::namespaces[namespaceName];
	if (declNamespace == nullptr)
		Exit("field: namespace not found. Namespace: "_ss + namespaceName, 16);
	Class* declClass = declNamespace->GetClass(declClassName);
	if (declClass == nullptr)
		Exit("field: class not found. Class: "_ss + declClassName, 17);

	Field* field = new Field(accessModifier, isStatic, dataType, declClassName, name);
	declClass->AddField(field);
}

void OpField::Parse(ifstream& device)
{
	accessModifier = static_cast<AccessModifier>(ByteArrayRead::ReadByte(device));
	isStatic = ByteArrayRead::ReadByte(device);
	dataType = ByteArrayRead::ReadSizeAndString(device);
	namespaceName = ByteArrayRead::ReadSizeAndString(device);
	declClassName = ByteArrayRead::ReadSizeAndString(device);
	name = ByteArrayRead::ReadSizeAndString(device);
}
