#pragma once
#include "OpBase.h"

class OpJmp : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;

private:
	size_t offset = 0;
};