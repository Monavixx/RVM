#pragma once
#include "OpBase.h"

class OpSetpd : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;
};