#pragma once
#include "OpBase.h"

class OpSetfield : public OpBase
{
public:
	OpSetfield()
	{}
	void Run() override;
	void Parse(HANDLE& device) override;
private:
	String name;
};