#pragma once
#include "OpBase.h"

class OpGc : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;
};