#pragma once
#include "OpBase.h"
#include "../Std/StdClassList.h"

class OpMul : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;
};