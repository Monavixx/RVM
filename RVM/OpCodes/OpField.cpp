#include "OpField.h"
#include "../Core/FieldObject.h"

void OpField::Run()
{
	Field* field = new Field(accessModifier, isStatic, dataType, declClassName, name);
	declClass->AddField(field);
}

void OpField::Parse(HANDLE& device)
{
	accessModifier = static_cast<AccessModifier>(ByteArrayRead::ReadByte(device));
	isStatic = ByteArrayRead::ReadByte(device);
	dataType = ByteArrayRead::ReadSizeAndString(device);
	declClassName = ByteArrayRead::ReadSizeAndString(device);
	name = ByteArrayRead::ReadSizeAndString(device);
	
	declClass = GlobalVariables::classes[declClassName];
	if (declClass == nullptr)
		Exit("field: decl class not found");
}
