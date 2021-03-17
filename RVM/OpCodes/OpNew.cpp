#include "OpNew.h"

void OpNew::Run()
{
	methodConstruction->CallMethod(frame);
}

void OpNew::Parse(HANDLE& device)
{
	className = ByteArrayRead::ReadSizeAndString(device);
	int amountParameters = ByteArrayRead::ReadInt(device);

	for (int i = 0; i < amountParameters; ++i)
	{
		Parameter parameter(ByteArrayRead::ReadSizeAndString(device));
		parameters.push_back(parameter);
	}

	declClass = GlobalVariables::classes[className];
	if (declClass == nullptr)
		Exit("new: class not exists");

	methodConstruction = declClass->GetMethod(className, parameters);
	if (methodConstruction == nullptr)
	{
	}
}
