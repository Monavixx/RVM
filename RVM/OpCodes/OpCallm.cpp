#include "OpCallm.h"

void OpCallm::Run()
{
	callableMethod->CallMethod(frame);
}

void OpCallm::Parse(HANDLE& device)
{
	isStatic = ByteArrayRead::ReadByte(device);
	declClassName = ByteArrayRead::ReadSizeAndString(device);
	name = ByteArrayRead::ReadSizeAndString(device);
	int amountParameters = ByteArrayRead::ReadInt(device);

	for (int i = 0; i < amountParameters; ++i)
	{
		String parameterDataType = ByteArrayRead::ReadSizeAndString(device);
		Parameter parameter(parameterDataType);
		parameters.push_back(parameter);
	}

	declClass = GlobalVariables::classes[declClassName];
	if (declClass == nullptr)
		Exit("Callm: class not found");

	callableMethod = declClass->GetMethod(name, parameters);
	if (callableMethod == nullptr)
		Exit("Callm: method not found");
}