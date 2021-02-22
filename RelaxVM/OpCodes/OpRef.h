#pragma once
#include "OpBase.h"

class OpRef : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;

private:
	QString dataType;
};