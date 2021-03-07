#pragma once
#include "OpBase.h"
#include "../Std/DataTypes/RelaxBool.h"

class OpPushBool : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;
private:
	bool data;
};