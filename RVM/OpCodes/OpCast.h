#pragma once
#include "OpBase.h"
#include "../Functions/ExecuteMethod.h"

class OpCast : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;

private:
	String dataType;
	ValueType newValueType;
};