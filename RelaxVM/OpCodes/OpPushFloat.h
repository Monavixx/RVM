#pragma once
#include "OpBase.h"
#include "../Std/DataTypes/RelaxFloat.h"

class OpPushFloat : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;
private:
	float data;
};