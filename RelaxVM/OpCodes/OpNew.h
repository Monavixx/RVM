#pragma once
#include "OpBase.h"
#include <vector>

class OpNew : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	String className;
	std::vector<Parameter> parameters;
	Class* declClass;
	IMethod* methodConstruction;
};

