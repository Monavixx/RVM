#pragma once
#include "OpBase.h"
#include "../Enums/Instruction.h"
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
#include "OpCast.h"
#include "OpMaxStack.h"
#include "OpRef.h"
#include "OpDeref.h"
#include "OpSetpd.h"
#include "OpThis.h"
#include "OpSetfield.h"
#include "OpGetfield.h"
#include "OpEqual.h"
#include "../Core/Method.h"

#include <vector>

class OpMethod : public OpBase
{
public:
	void Run() override;
	void Parse(ifstream& device) override;
	void ParseCode(ifstream& device);

private:
	void ParseOpCode(Instruction instruction, ifstream& device);

	AccessModifier accessModifier;
	bool isStatic;
	String dataType;
	String declClassName;
	String name;
	std::vector<Parameter> parameters;
	std::vector<OpBase*> methodCode;
	size_t peekCode;
	size_t sizeCode;
	Method* method;
};

