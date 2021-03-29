#pragma once
#include "OpBase.h"

class OpPushStr : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;

private:
	String data;
};


