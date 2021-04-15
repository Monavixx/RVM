#include "OpClass.h"
#include "../Core/FieldObject.h"

void OpClass::Run()
{
	Namespace* declNamespace = GlobalVariables::namespaces[namespaceName];
	if (declNamespace == nullptr)
		Exit("class: namespace not found");
	declNamespace->AddClass(new Class(className));
}

void OpClass::Parse(ifstream& device)
{
	namespaceName = ByteArrayRead::ReadSizeAndString(device);
	className = ByteArrayRead::ReadSizeAndString(device);
}
