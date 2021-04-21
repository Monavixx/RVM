#include "OpCallm.h"
#include "../Core/FieldObject.h"

void OpCallm::Run()
{
	callableMethod->CallMethod(frame);
}

void OpCallm::Parse(ifstream& device)
{
	isStatic = ByteArrayRead::ReadByte(device);
	namespaceName = ByteArrayRead::ReadSizeAndString(device);
	declClassName = ByteArrayRead::ReadSizeAndString(device);
	name = ByteArrayRead::ReadSizeAndString(device);
	int amountParameters = ByteArrayRead::ReadInt(device);

	for (int i = 0; i < amountParameters; ++i)
	{
		String parameterNamespace = ByteArrayRead::ReadSizeAndString(device);
		String parameterDataType = ByteArrayRead::ReadSizeAndString(device);
		Parameter parameter(parameterNamespace, parameterDataType);
		parameters.push_back(parameter);
	}
	Namespace* declNamespace = GlobalVariables::namespaces[namespaceName];
	if(declNamespace == nullptr)
		Exit("callm: namespace not found. Namespace: "_ss + namespaceName, 6);

	Class* declClass = declNamespace->GetClass(declClassName);
	if (declClass == nullptr)
		Exit("callm: class not found. Class: "_ss + declClassName, 7);

	callableMethod = declClass->GetMethod(name, parameters);
	if (callableMethod == nullptr)
		Exit("callm: method not found. Method: "_ss + name + ([&]() {String res; for (auto& item : parameters) { res += item.GetDataType()->GetFullName() + " "_ss; }; return res; })(), 8);

}