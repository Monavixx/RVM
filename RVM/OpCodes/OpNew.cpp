#include "OpNew.h"
#include "../Core/FieldObject.h"
#include "../Std/Classes/CustomObject.h"

void OpNew::Run()
{
	if (declClass->IsStd())
	{
		methodConstruction->CallMethod(frame);
	}
	else
	{
		Object* newObject = new CustomObject(declClass);
		GlobalVariables::heap.push_back(newObject);
		Value* value = new Value(ValueType::OBJECT, UValue(newObject));
		frame->GetStack().push(value);
		methodConstruction->CallMethod(frame);
		frame->GetStack().push(value);
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
	if (methodConstruction == nullptr)
		Exit("new: Constructor not found!");
}
