#pragma once
#include <QtCore>

#include "ByteArrayLib.h"
#include "ConsoleTextStream.h"
#include "Exceptions/ExitException.h"
#include "Functions/Exit.h"
#include "Class.h"
#include "Instruction.h"
#include "ClassList.h"
#include "Object.h"
#include "RelaxString.h"
#include "RelaxInt32.h"
#include "RelaxBool.h"
#include "Variable.h"
#include "Heap.h"
#include "StdClass.h"
#include "StdClassList.h"
#include "Stack.h"
#include "Frame.h"
#include "Args.h"

class VirtualMachine
{
public:
	VirtualMachine();
	~VirtualMachine();
	void Start();
	void ProcessInstructionExecuting(Instruction instruction, QIODevice& device, Frame& frame);
	void ProccesInstructionCreating(Instruction instruction, QIODevice& device);


	void CreateMainClass(QIODevice& device);
	void CreateClass(QIODevice& device);
	void CreateMethod(QIODevice& device);

	void CallMethod(QIODevice& device);
	void PushStr(QIODevice& device);
	void PushInt32(QIODevice& device);
	void Return(QIODevice& device);
	void New(QIODevice& device);
	void Set(QIODevice& device, Frame& currentFrame);
	void Get(QIODevice& device, Frame& currentFrame);
	void Local(QIODevice& device, Frame& currentFrame);
	void Dup(QIODevice& device);
	void Add(QIODevice& device);
	void Jmp(QIODevice& device);
	void Jmpif(QIODevice& device);
	void Gc(QIODevice& device);
	void Newarr(QIODevice& device);
	void Getarr(QIODevice& device, Frame& currentFrame);
	void Setarr(QIODevice& device, Frame& currentFrame);
	void PushBool(QIODevice& device);

private:
	QString filename;
	QFile executableFile;
	Class* mainClass;
	ClassList classes;
	Stack stack;
	Heap heap;
};

