#pragma once
#include "OpBase.h"
#include "RelaxBool.h"

class OpJmpif : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;

private:
	int offset;
};