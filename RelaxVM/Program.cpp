#include "Program.h"

Program::Program(int argc, char* argv[])
{
	for (int i = 0; i < argc; ++i)
	{
		this->argv << argv[i];
	}
}

void Program::Start()
{
	if (IsLaunch())
	{
		VirtualMachine virtualMachine(argv);
		virtualMachine.Start();
	}
}

bool Program::IsLaunch()
{
	return !argv[1].startsWith("-");
}
