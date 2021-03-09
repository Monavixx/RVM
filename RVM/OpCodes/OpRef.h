#pragma once
#include "OpBase.h"

class OpRef : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	String dataType;
};