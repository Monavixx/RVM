#pragma once
#include <QtCore>
#include "MethodSignature.h"
#include "AccessModifier.h"

class Method
{
public:
	Method();

private:
	MethodSignature signature;
	AccessModifier accessModifier;
	bool isStatic;
};

