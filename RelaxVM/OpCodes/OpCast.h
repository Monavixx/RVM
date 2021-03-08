#pragma once
#include "OpBase.h"
#include "../Functions/ExecuteMethod.h"

class OpCast : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	String dataType;
	Class* declClass;
};