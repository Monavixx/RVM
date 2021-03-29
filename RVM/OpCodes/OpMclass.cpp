#include "OpMclass.h"
#include "../Core/FieldObject.h"

void OpMclass::Run()
{
	Class* newClass = new Class(className);
	GlobalVariables::classes.AddClass(newClass);
	GlobalVariables::mainClass = newClass;
}

void OpMclass::Parse(ifstream& device)
{
	className = ByteArrayRead::ReadSizeAndString(device);
}
