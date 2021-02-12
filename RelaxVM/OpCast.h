#pragma once
#include "OpBase.h"
#include "StdClassList.h"
#include "ExecuteMethod.h"

class OpCast : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;

private:
	QString dataType;
	bool isStd;
};