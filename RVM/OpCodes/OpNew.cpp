#include "OpNew.h"
#include "../Core/FieldObject.h"
#include "../Std/Classes/CustomObject.h"

void OpNew::Run()
{
	if(declClass->IsStd())
		methodConstruction->CallMethod(frame);
	else
	{
		Object* newObject = new CustomObject(declClass);
		GlobalVariables::heap.push_back(newObject);
		frame->GetStack().push(new Value(ValueType::OBJECT, UValue(newObject)));
	}
}

void OpNew::Parse(ifstream& device)
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
}
