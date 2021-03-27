#pragma once
#include "OpBase.h"

class OpEqual : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;
};