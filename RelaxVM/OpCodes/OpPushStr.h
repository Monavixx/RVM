#pragma once
#include "OpBase.h"
#include "../Std/DataTypes/RelaxString.h"

class OpPushStr : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	String data;
};


