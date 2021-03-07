#pragma once
#include "OpBase.h"

class OpClass : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	String className;
};

