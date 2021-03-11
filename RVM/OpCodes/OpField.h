#pragma once
#include "OpBase.h"

class OpField : public OpBase
{
public:
	void Run() override;
	void Parse(HANDLE& device) override;

private:
	AccessModifier accessModifier;
	bool isStatic;
	String dataType;
	String declClassName;
	String name;
	Class* declClass;
};