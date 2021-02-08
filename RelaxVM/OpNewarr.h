#pragma once
#include "OpBase.h"
#include "RelaxInt32.h"
#include "RelaxArray.h"

class OpNewarr : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;

private:
	QString dataType;
};