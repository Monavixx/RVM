#pragma once
#include "OpBase.h"
#include "../Std/Classes/RelaxArray.h"

class OpSetarr : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;
};