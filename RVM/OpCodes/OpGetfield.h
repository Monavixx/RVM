#pragma once
#include "OpBase.h"

class OpGetfield : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;

private:
	String name;
};