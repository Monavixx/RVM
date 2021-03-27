#include "Program.h"
#include "Core/FieldObject.h"

Program::Program()
{
}

Program::~Program()
{
}

void Program::Start()
{
	if (IsLaunch())
	{
		VirtualMachine virtualMachine;
		virtualMachine.Start();
	}
}

bool Program::IsLaunch()
{
	return !Args::args[1].startsWith("-");
}
