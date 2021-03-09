#pragma once
#include "OpBase.h"

class OpGet : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	size_t id = 0;
};

