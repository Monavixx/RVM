#pragma once
#include "OpBase.h"

class OpCe : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;
};