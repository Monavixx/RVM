#pragma once
#include "OpBase.h"
#include "RelaxInt32.h"

class OpMaxStack : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;

private:
	int size;
};