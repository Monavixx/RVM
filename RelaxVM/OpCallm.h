#pragma once
#include "OpBase.h"
#include "StdClassList.h"
#include "Instruction.h"
#include "ExecuteMethod.h"


class OpCallm : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;

private:
	bool isStd;
	bool isStatic;
	QString declClassName;
	QString name;
	QVector<Parameter> parameters;
	StdClass* stdClass;
	StdMethod* callableStdMethod;
};


