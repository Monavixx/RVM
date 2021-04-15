#include "OpNamespace.h"

void OpNamespace::Run()
{
	GlobalVariables::namespaces.AddNamespace(new Namespace(namespaceName));
}

void OpNamespace::Parse(ifstream& device)
{
	namespaceName = ByteArrayRead::ReadSizeAndString(device);
}
