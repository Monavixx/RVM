#include "OpSetfield.h"
#include "../Core/FieldObject.h"

void OpSetfield::Run()
{
	if (isStatic)
	{
		declClass->SetStaticField(fieldName, frame->GetStack().pop());
	}
	else
	{
		Object* target = GlobalVariables::heap[get<size_t>(frame->GetStack().pop()->value)];
		target->SetField(fieldName, frame->GetStack().pop());
	}
}

void OpSetfield::Parse(ifstream& device)
{
	isStatic = ByteArrayRead::ReadByte(device);
	if (isStatic)
	{
		namespaceName = ByteArrayRead::ReadSizeAndString(device);
		className = ByteArrayRead::ReadSizeAndString(device);
		Namespace* declNamespace = GlobalVariables::namespaces[namespaceName];
		if (declNamespace == nullptr)
			Exit("getfield: namespace not found");
		declClass = declNamespace->GetClass(className);
		if (declClass == nullptr)
			Exit("getfield: class not found");
	}
	fieldName = ByteArrayRead::ReadSizeAndString(device);
}
