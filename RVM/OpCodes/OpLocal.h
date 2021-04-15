#pragma once
#include "OpBase.h"

class OpLocal : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;
private:
	size_t id = 0;
	String namespaceName;
	String dataType;
	Class* dataTypeClass;
};