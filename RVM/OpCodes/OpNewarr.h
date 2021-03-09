#pragma once
#include "OpBase.h"
#include "../Std/Classes/RelaxInt32.h"
#include "../Std/Classes/RelaxArray.h"

class OpNewarr : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	String dataType;
};