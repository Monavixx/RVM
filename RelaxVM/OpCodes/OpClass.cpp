#include "OpClass.h"

void OpClass::Run()
{
	GlobalVariables::classes.push_back(new Class(className));
}

void OpClass::Parse(HANDLE& device)
{
	className = ByteArrayRead::ReadSizeAndString(device);
}
