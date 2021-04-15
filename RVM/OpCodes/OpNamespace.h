#pragma once
#include "OpBase.h"

class OpNamespace : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;

private:
	String namespaceName;
};

