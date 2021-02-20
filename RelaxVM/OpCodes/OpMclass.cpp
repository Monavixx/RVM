#include "OpMclass.h"

void OpMclass::Run()
{
	Class* newClass = new Class(className);
	GlobalVariables::classes.push_back(newClass);
	GlobalVariables::mainClass = newClass;
}

void OpMclass::Parse(QIODevice& device)
{
	className = ByteArrayRead::ReadSizeAndString(device);
}
