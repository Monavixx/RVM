#pragma once
#include "OpBase.h"
#include "RelaxFloat.h"

class OpPushFloat : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;
private:
	float data;
};