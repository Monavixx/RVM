#pragma once
#include "OpBase.h"
#include "../Std/StdClassList.h"
#include "../Functions/ExecuteMethod.h"

class OpCast : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;

private:
	QString dataType;
	bool isStd;
	Class* declClass;
	StdClass* declStdClass;
};