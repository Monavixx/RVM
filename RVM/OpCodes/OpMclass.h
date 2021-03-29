#pragma once
#include "OpBase.h"

class OpMclass : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;

private:
	String className;
};

