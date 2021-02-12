#pragma once
#include "OpBase.h"
#include "Instruction.h"
#include "OpAdd.h"
#include "OpBase.h"
#include "OpCallm.h"
#include "OpClass.h"
#include "OpDiv.h"
#include "OpDup.h"
#include "OpGc.h"
#include "OpGet.h"
#include "OpGetarr.h"
#include "OpJmp.h"
#include "OpJmpif.h"
#include "OpLocal.h"
#include "OpMclass.h"
#include "OpMethod.h"
#include "OpMul.h"
#include "OpNew.h"
#include "OpNewarr.h"
#include "OpPushBool.h"
#include "OpPushFloat.h"
#include "OpPushint32.h"
#include "OpPushStr.h"
#include "OpReturn.h"
#include "OpSet.h"
#include "OpSetarr.h"
#include "OpSub.h"

class OpMethod : public OpBase
{
public:
	void Run() override;
	void Parse(QIODevice& device) override;

private:

	void ParseOpCode(Instruction instruction, QIODevice& device);

	AccessModifier accessModifier;
	bool isStatic;
	QString dataType;
	QString declClassName;
	QString name;
	QVector<Parameter> parameters;
	QVector<OpBase*> methodCode;
};

