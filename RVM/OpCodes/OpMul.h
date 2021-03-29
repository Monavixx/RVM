#pragma once
#include "OpBase.h"

class OpMul : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;
};