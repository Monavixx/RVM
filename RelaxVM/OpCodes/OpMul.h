#pragma once
#include "OpBase.h"

class OpMul : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;
};