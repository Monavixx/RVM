#include "Program.h"

Program::Program(int argc, char* argv[])
{
	for (int i = 0; i < argc; ++i)
	{
		this->argv << argv[i];
	}
}

Program::~Program()
{
}

void Program::Start()
{
	if (IsLaunch())
	{
		if (argv.contains("-a"))
		{
			AsmCompiler asmCompiler(argv);
			asmCompiler.Start();
		}
		else
		{
			Compiler compiler(argv);
			compiler.Start();
		}
		
	}
}

bool Program::IsLaunch()
{
	return !argv[1].startsWith("-");
}
