#pragma once
#include <QtCore>

#include "../Libs/ByteArrayLib.h"
#include "../Libs/ConsoleTextStream.h"
#include "Exceptions/ExitException.h"
#include "Functions/Exit.h"
#include "Class.h"
#include "Instruction.h"
#include "ClassList.h"
#include "Object.h"
#include "RelaxString.h"

class VirtualMachine
{
public:
	VirtualMachine(const QStringList& argv);
	~VirtualMachine();
	void Start();
	void ProcessInstruction(Instruction instruction);

private:
	QStringList arguments;
	QString filename;
	QFile executableFile;
	Class* mainClass;
	ClassList classes;
	QStack<Object*> stack;
};

