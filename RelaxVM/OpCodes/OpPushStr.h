#pragma once
#include "OpBase.h"
#include "../Std/DataTypes/RelaxString.h"

class OpPushStr : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;

private:
	QString data;
};


