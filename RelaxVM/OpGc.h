#pragma once
#include "OpBase.h"
#include <algorithm>

class OpGc : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;
};