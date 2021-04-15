#include "OpMclass.h"
#include "../Core/FieldObject.h"

void OpMclass::Run()
{
	Namespace* declNamespace = GlobalVariables::namespaces[namespaceName];
	Class* newClass = new Class(className);
	declNamespace->AddClass(newClass);
	GlobalVariables::mainClass = newClass;
}

void OpMclass::Parse(ifstream& device)
{
	namespaceName = ByteArrayRead::ReadSizeAndString(device);
	className = ByteArrayRead::ReadSizeAndString(device);
}
