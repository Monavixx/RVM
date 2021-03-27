#pragma once
#include "OpBase.h"

class OpPushBool : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;
private:
	bool data = false;
};