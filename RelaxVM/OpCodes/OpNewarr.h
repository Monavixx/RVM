#pragma once
#include "OpBase.h"
#include "../Std/DataTypes/RelaxInt32.h"
#include "../Std/DataTypes/RelaxArray.h"

class OpNewarr : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	String dataType;
};