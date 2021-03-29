#pragma once
#include "OpBase.h"

class OpAdd : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;
};