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
		Value* value = new Value(ValueType::OBJECT, UValue(newObject->GetAddress()));
		frame->GetStack().push(value);
		methodConstruction->CallMethod(frame);
		frame->GetStack().push(value);
	}
}

void OpNew::Parse(ifstream& device)
{
	namespaceName = ByteArrayRead::ReadSizeAndString(device);
	className = ByteArrayRead::ReadSizeAndString(device);
	int amountParameters = ByteArrayRead::ReadInt(device);

	for (int i = 0; i < amountParameters; ++i)
	{
		Parameter parameter(ByteArrayRead::ReadSizeAndString(device), ByteArrayRead::ReadSizeAndString(device));
		parameters.push_back(parameter);
	}
	Namespace* declNamespace = GlobalVariables::namespaces[namespaceName];
	if (declNamespace == nullptr)
	{
		Exit("new: namespace not found");
	}
	declClass = declNamespace->GetClass(className);
	if (declClass == nullptr)
		Exit("new: class not found");

	methodConstruction = declClass->GetMethod(className, parameters);
	if (methodConstruction == nullptr)
		Exit("new: constructor not found");
}
