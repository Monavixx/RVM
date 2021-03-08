#pragma once
#include "OpCodes/OpMethod.h"

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

