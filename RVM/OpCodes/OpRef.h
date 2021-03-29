#pragma once
#include "OpBase.h"

class OpRef : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;

private:
	String dataType;
};