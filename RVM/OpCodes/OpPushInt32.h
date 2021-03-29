#pragma once
#include "OpBase.h"

class OpPushInt32 : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;

private:
	int data = 0;
};