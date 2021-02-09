#pragma once
#include "OpBase.h"
#include "StdClassList.h"
#include "Instruction.h"
#include "OpReturn.h"
using std::vector;

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
	vector<Parameter> parameters;
};


