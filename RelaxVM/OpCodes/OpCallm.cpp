#include "OpCallm.h"

void OpCallm::Run()
{
	if (isStd)
	{
		callableStdMethod->CallFunction(gv, frame);
	}
	else
	{
		Class* declClass = gv->classes.FindClassByName(declClassName);
		if (declClass == nullptr)
			Exit("Callm: class not found");

		Method* callableMethod = declClass->GetMethod(name, parameters);
		if (callableMethod == nullptr)
			Exit("Callm: method not found");

		callableMethod->CallMethod(gv, frame);
	}
}

void OpCallm::Parse(QIODevice& device)
{
	isStd = ByteArrayRead::ReadByte(device);
	isStatic = ByteArrayRead::ReadByte(device);
	declClassName = ByteArrayRead::ReadSizeAndString(device);
	name = ByteArrayRead::ReadSizeAndString(device);
	int amountParameters = ByteArrayRead::ReadInt(device);

	for (int i = 0; i < amountParameters; ++i)
	{
		QString parameterDataType = ByteArrayRead::ReadSizeAndString(device);
		Parameter parameter(parameterDataType);
		parameters.push_back(parameter);
	}

	if (isStd)
	{
		stdClass = (*StdClassList::GetInstance())[declClassName];
		if (stdClass == nullptr)
			Exit("std class not exists");

		callableStdMethod = stdClass->GetMethod(name, parameters);
		if (callableStdMethod == nullptr)
			Exit("std method not exists");
	}
}