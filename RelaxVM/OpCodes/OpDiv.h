#pragma once
#include "OpBase.h"
#include "../Std/StdClassList.h"

class OpDiv : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;
};