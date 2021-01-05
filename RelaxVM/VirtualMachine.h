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
#include "Heap.h"
#include "Stack.h"
#include "StdTypesConstructors.h"
#include "StdClass.h"
#include "StdClassList.h"

class VirtualMachine
{
public:
	VirtualMachine(const QStringList& argv);
	~VirtualMachine();
	void Start();
	void ProcessInstructionExecuting(Instruction instruction, QIODevice& device);
	void ProccesInstructionCreating(Instruction instruction, QIODevice& device);


	void CreateMainClass(QIODevice& device);
	void CreateClass(QIODevice& device);
	void CreateMethod(QIODevice& device);

	void CreateVar(QIODevice& device);
	void CallMethod(QIODevice& device);
	void Push(QIODevice& device);
	void PushStr(QIODevice& device);
	void Return(QIODevice& device);

private:
	QStringList arguments;
	QString filename;
	QFile executableFile;
	Class* mainClass;
	ClassList classes;
	Stack stack;
	Heap heap;
};

