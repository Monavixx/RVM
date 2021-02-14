#pragma once
#include "OpBase.h"

class OpJmp : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;

private:
	int offset;
};