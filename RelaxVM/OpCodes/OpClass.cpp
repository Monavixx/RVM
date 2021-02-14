#include "OpClass.h"

void OpClass::Run()
{
	gv->classes.push_back(new Class(className));
}

void OpClass::Parse(QIODevice& device)
{
	className = ByteArrayRead::ReadSizeAndString(device);
}
