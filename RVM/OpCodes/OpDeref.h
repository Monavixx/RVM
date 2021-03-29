#pragma once
#include "OpBase.h"

class OpDeref : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;
};