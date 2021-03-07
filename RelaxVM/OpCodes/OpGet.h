#pragma once
#include "OpBase.h"
#include "../Std/StdClassList.h"

class OpGet : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	size_t id;
};

