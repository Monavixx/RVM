#pragma once
#include "OpBase.h"

class OpJmpif : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	size_t offset = 0;
};