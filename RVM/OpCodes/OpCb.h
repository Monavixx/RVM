#pragma once
#include "OpBase.h"

class OpCb : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;
};