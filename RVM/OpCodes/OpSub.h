#pragma once
#include "OpBase.h"

class OpSub : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;
};