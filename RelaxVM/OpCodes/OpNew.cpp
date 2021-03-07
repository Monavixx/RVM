#include "OpNew.h"

void OpNew::Run()
{
	Object* object = nullptr;
	if (isStd)
	{
		stdMethodConstruction->CallFunction(frame);
	}
	else
	{
		methodConstruction->CallMethod(frame);
	}
}

void OpNew::Parse(HANDLE& device)
{
	isStd = ByteArrayRead::ReadByte(device);
	className = ByteArrayRead::ReadSizeAndString(device);
	int amountParameters = ByteArrayRead::ReadInt(device);

	for (int i = 0; i < amountParameters; ++i)
	{
		Parameter parameter(ByteArrayRead::ReadSizeAndString(device));
		parameters.push_back(parameter);
	}

	if (isStd)
	{
		stdClass = (*StdClassList::GetInstance())[className];
		if (stdClass == nullptr)
			Exit("new: Std class not exists");

		stdMethodConstruction = stdClass->GetMethod(className, parameters);
		if (stdMethodConstruction == nullptr)
			Exit("new: Construction not exists");
	}
	else
	{
		usrClass = GlobalVariables::classes.FindClassByName(className);
		if (stdClass == nullptr)
			Exit("new: Std class not exists");

		methodConstruction = usrClass->GetMethod(className, parameters);
		if (stdMethodConstruction == nullptr)
			Exit("new: Construction not exists");
	}
}
