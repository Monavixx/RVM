#pragma once
#include <QtCore>

#include "OpCodes/OpMethod.h"

class VirtualMachine
{
public:
	VirtualMachine();
	~VirtualMachine();
	void Start();
	void ParseCode(Instruction instruction);

private:
	QVector<OpBase*> opCodes;
};

