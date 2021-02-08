#pragma once
#include "OpBase.h"
#include "RelaxBool.h"

class OpPushBool : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;
private:
	bool data;
};