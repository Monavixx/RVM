#include "Compiler.h"

Compiler::Compiler(const QStringList& argv) : agruments(argv)
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
}

