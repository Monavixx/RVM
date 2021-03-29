#pragma once
#include "OpBase.h"
#include <vector>

class OpNew : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;

private:
	String className;
	std::vector<Parameter> parameters;
	Class* declClass = nullptr;
	IMethod* methodConstruction = nullptr;
};

