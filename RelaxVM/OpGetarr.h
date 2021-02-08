#pragma once
#include "OpBase.h"
#include "RelaxArray.h"
#include "RelaxInt32.h"

class OpGetarr : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;
};