#pragma once
#include "OpBase.h"
#include "../Std/StdClassList.h"
#include "../Functions/ExecuteMethod.h"

class OpCast : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	String dataType;
	bool isStd;
	Class* declClass;
	StdClass* declStdClass;
};