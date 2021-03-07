#pragma once
#include "OpBase.h"

class OpLocal : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;
private:
	size_t id;
	String dataType;
};