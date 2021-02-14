#pragma once
#include "OpBase.h"
#include "../Std/DataTypes/RelaxArray.h"
#include "../Std/DataTypes/RelaxInt32.h"

class OpGetarr : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;
};