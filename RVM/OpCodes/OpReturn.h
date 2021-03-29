#pragma once
#include "OpBase.h"

class OpReturn : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;
};