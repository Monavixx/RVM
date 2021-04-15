#pragma once
#include "OpBase.h"

class OpField : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;

private:
	AccessModifier accessModifier;
	bool isStatic;
	String dataType;
	String namespaceName;
	String declClassName;
	String name;
};