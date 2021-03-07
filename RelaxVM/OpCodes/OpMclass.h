#pragma once
#include "OpBase.h"

class OpMclass : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	String className;
};

