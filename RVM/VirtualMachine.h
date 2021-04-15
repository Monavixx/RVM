#pragma once
#include "OpCodes/OpMethod.h"
#include "OpCodes/OpField.h"
#include "OpCodes/OpNamespace.h"
#include <time.h>

class VirtualMachine
{
public:
	VirtualMachine();
	~VirtualMachine();
	void Start();
	void ParseCode(Instruction instruction);

private:
	std::vector<OpBase*> opCodes;
};

