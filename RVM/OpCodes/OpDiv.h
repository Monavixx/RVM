#pragma once
#include "OpBase.h"

class OpDiv : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;
};