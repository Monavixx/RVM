#pragma once
#include "OpBase.h"

class OpCle : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;
};