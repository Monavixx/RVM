#pragma once
#include "OpBase.h"

class OpGetfield : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;

private:
	bool isStatic;
	String namespaceName;
	String className;
	Class* declClass = nullptr;
	String fieldName;
};