#pragma once
#include "OpBase.h"

class OpThis : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;
};