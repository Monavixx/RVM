#include "OpNew.h"
#include "../Std/Classes/CustomObject.h"

void OpNew::Run()
{
	if(declClass->IsStd())
		methodConstruction->CallMethod(frame);
	else
	{
		frame->GetStack().push(GlobalVariables::heap.push_back(new CustomObject(declClass)));
	}
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
	/*if (methodConstruction == nullptr)
		Exit("new: constructor not found!");*/
}
