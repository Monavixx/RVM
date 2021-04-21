#include "OpGetfield.h"
#include "../Core/FieldObject.h"

void OpGetfield::Run()
{
	if (isStatic)
	{
		frame->GetStack().push(declClass->GetStaticField(fieldName)->value);
	}
	else
	{
		Value* data = frame->GetStack().pop();
		frame->GetStack().push(GlobalVariables::heap[get<size_t>(data->value)]->GetField(fieldName)->value);
	}
}

void OpGetfield::Parse(ifstream& device)
{
	isStatic = ByteArrayRead::ReadByte(device);
	if (isStatic)
	{
		namespaceName = ByteArrayRead::ReadSizeAndString(device);
		className = ByteArrayRead::ReadSizeAndString(device);
		Namespace* declNamespace = GlobalVariables::namespaces[namespaceName];
		if (declNamespace == nullptr)
			Exit("getfield: namespace not found. Namespace: "_ss + namespaceName, 20);
		declClass = declNamespace->GetClass(className);
		if (declClass == nullptr)
			Exit("getfield: class not found. Class: "_ss + className, 21);
	}
	fieldName = ByteArrayRead::ReadSizeAndString(device);
}
