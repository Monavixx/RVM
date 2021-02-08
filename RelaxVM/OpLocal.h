#pragma once
#include "OpBase.h"

class OpLocal : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;
private:
	int id;
	QString dataType;
};