#pragma once
#include "OpBase.h"
#include "../Std/StdClassList.h"
#include <vector>

class OpNew : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	bool isStd;
	String className;
	std::vector<Parameter> parameters;
	StdClass* stdClass;
	StdMethod* stdMethodConstruction;
	Class* usrClass;
	Method* methodConstruction;
};

