#pragma once
#include "OpBase.h"
#include "../Std/Classes/RelaxFloat.h"

class OpPushFloat : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;
private:
	float data = 0.f;
};