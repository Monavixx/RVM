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
#include "RelaxArray.h"
#include "RelaxInt32.h"
#include "RelaxBool.h"
#include "Variable.h"
#include "Heap.h"
#include "StdClass.h"
#include "GlobalVariables.h"
#include "StdClassList.h"
#include "Stack.h"
#include "Frame.h"
#include "Args.h"
#include "OpBase.h"
#include "OpMclass.h"
#include "OpClass.h"
#include "OpMethod.h"
#include "OpCast.h"

class VirtualMachine
{
public:
	VirtualMachine();
	~VirtualMachine();
	void Start();
	void ParseCode(Instruction instruction);

private:
	GlobalVariables* gv;
	QVector<OpBase*> opCodes;
};

