#pragma once
#include <QtCore>
#include "Compiler.h"
#include "AsmCompiler.h"

class Program
{
public:
	Program(int argc, char* argv[]);
	~Program();

	void Start();
	bool IsLaunch();

private:
	QStringList argv;
};