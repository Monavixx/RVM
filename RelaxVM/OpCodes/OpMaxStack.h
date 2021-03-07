#pragma once
#include "OpBase.h"
#include "../Std/DataTypes/RelaxInt32.h"

class OpMaxStack : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	size_t size;
};