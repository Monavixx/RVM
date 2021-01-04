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
#include "Variable.h"

class VirtualMachine
{
public:
	VirtualMachine(const QStringList& argv);
	~VirtualMachine();
	void Start();
	void ProcessInstructionExecuting(Instruction instruction, QIODevice& device);
	void ProccesInstructionCreating(Instruction instruction, QIODevice& device);
private:
	QStringList arguments;
	QString filename;
	QFile executableFile;
	Class* mainClass;
	ClassList classes;
	QStack<Object*> stack;
	QList<Variable> heap;
};

