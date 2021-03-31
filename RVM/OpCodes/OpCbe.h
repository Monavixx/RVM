#pragma once
#include "OpBase.h"

class OpCbe : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;
};