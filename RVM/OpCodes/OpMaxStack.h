#pragma once
#include "OpBase.h"

class OpMaxStack : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	size_t size = 0;
};