#include "OpMclass.h"

void OpMclass::Run()
{
	Class* newClass = new Class(className);
	gv->classes.push_back(newClass);
	gv->mainClass = newClass;
}

void OpMclass::Parse(QIODevice& device)
{
	className = ByteArrayRead::ReadSizeAndString(device);
}
