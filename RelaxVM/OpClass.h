#pragma once
#include "OpBase.h"

class OpClass : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;

private:
	QString className;
};

