#pragma once
#include "OpBase.h"
#include "StdClassList.h"
#include "Instruction.h"
#include "OpReturn.h"


class OpCallm : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;

private:
	void ExecuteMethod();
	bool isStd;
	bool isStatic;
	QString declClassName;
	QString name;
	QList<Parameter> parameters;
};


