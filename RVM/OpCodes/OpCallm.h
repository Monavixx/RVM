#pragma once
#include "OpBase.h"
#include "../Enums/Instruction.h"
#include "../Functions/ExecuteMethod.h"
#include <vector>


class OpCallm : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;

private:
	bool isStatic;
	String namespaceName;
	String declClassName;
	String name;
	std::vector<Parameter> parameters;
	IMethod* callableMethod = nullptr;
};


