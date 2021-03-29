#pragma once
#include "OpBase.h"

class OpClass : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;

private:
	String className;
};

