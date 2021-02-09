#pragma once
#include "OpBase.h"
#include "StdClassList.h"

class OpNew : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;

private:
	bool isStd;
	QString className;
	QList<Parameter> parameters;
};

