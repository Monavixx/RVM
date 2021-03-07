#pragma once
#include "OpBase.h"

class OpJmp : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	size_t offset;
};