#include "OpClass.h"

void OpClass::Run()
{
	GlobalVariables::classes.AddClass(new Class(className));
}

void OpClass::Parse(HANDLE& device)
{
	className = ByteArrayRead::ReadSizeAndString(device);
}
