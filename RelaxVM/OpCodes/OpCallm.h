#pragma once
#include "OpBase.h"
#include "../Std/StdClassList.h"
#include "../Enums/Instruction.h"
#include "../Functions/ExecuteMethod.h"
#include <vector>


class OpCallm : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	bool isStd;
	bool isStatic;
	String declClassName;
	String name;
	std::vector<Parameter> parameters;
	StdClass* stdClass;
	StdMethod* callableStdMethod;
	Class* declClass;
	Method* callableMethod;
};


