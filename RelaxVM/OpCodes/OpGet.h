#pragma once
#include "OpBase.h"
#include "../Std/StdClassList.h"

class OpGet : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;

private:
	int id;
};

