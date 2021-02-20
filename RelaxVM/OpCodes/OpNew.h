#pragma once
#include "OpBase.h"
#include "../Std/StdClassList.h"

class OpNew : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;

private:
	bool isStd;
	QString className;
	QVector<Parameter> parameters;
	StdClass* stdClass;
	StdMethod* stdMethodConstruction;
	Class* usrClass;
	Method* methodConstruction;
};

