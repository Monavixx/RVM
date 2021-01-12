#include "Compiler.h"

Compiler::Compiler(const QStringList& argv) : arguments(argv)
{
	filename = argv[1];
	compilableFile.setFileName(filename);
}

Compiler::~Compiler()
{
	compilableFile.close();
}
 
void Compiler::Start()
{
	if (!compilableFile.open(QIODevice::ReadOnly))
	{
		Exit("File open error");
	}
	StartCompiling(compilableFile);
	
}

void Compiler::StartCompiling(QIODevice& file)
{

}

