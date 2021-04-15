#include "OpLocal.h"
#include "../Core/FieldObject.h"

void OpLocal::Run()
{
	frame->CreateVariable(id, dataTypeClass);
}

void OpLocal::Parse(ifstream& device)
{
	id = ByteArrayRead::ReadInt(device);
	namespaceName = ByteArrayRead::ReadSizeAndString(device);
	dataType = ByteArrayRead::ReadSizeAndString(device);

	Namespace* declNamespace = GlobalVariables::namespaces[namespaceName];
	if (declNamespace == nullptr)
		Exit("local: namespace not found");
	dataTypeClass = declNamespace->GetClass(dataType);
	if (dataTypeClass == nullptr)
		Exit("local: class not found");
}
