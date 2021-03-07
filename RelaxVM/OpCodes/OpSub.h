#pragma once
#include "OpBase.h"
#include "../Std/StdClassList.h"

class OpSub : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;
};