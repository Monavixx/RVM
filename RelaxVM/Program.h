#pragma once
#include <QtCore>

#include "VirtualMachine.h"

class Program
{
public:
	Program(int argc, char* argv[]);

	void Start();
	bool IsLaunch();

private:
	QStringList argv;
};