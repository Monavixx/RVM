#pragma once
#include "OpBase.h"

class OpSetfield : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;
};