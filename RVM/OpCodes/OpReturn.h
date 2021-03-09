#pragma once
#include "OpBase.h"

class OpReturn : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;
};