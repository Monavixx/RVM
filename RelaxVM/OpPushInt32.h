#pragma once
#include "OpBase.h"
#include "RelaxInt32.h"

class OpPushInt32 : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;

private:
	int data;
};