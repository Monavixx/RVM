#pragma once
#include "OpBase.h"

class OpCl : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;
};