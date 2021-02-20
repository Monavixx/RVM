#include "OpClass.h"

void OpClass::Run()
{
	GlobalVariables::classes.push_back(new Class(className));
}

void OpClass::Parse(QIODevice& device)
{
	className = ByteArrayRead::ReadSizeAndString(device);
}
