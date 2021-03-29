#pragma once
#include "OpBase.h"

class OpDup : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;
};