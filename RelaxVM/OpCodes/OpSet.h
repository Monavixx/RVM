#pragma once
#include "OpBase.h"

class OpSet : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;
private:
	int id;
};