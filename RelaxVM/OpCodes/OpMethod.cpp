#include "OpMethod.h"

void OpMethod::Run()
{
	method = new Method(name, dataType, declClassName, parameters, {}, accessModifier, isStatic);

	Class* _class = GlobalVariables::classes[declClassName];
	if (_class == nullptr)
	{
		Exit("method: decl class not found");
	}

	_class->AddMethod(method);
}

void OpMethod::Parse(HANDLE& device)
{
	accessModifier = static_cast<AccessModifier>(ByteArrayRead::ReadByte(device));
	isStatic = ByteArrayRead::ReadByte(device);

	dataType = ByteArrayRead::ReadSizeAndString(device);
	declClassName = ByteArrayRead::ReadSizeAndString(device);
	name = ByteArrayRead::ReadSizeAndString(device);

	int amountParameters = ByteArrayRead::ReadInt(device);

	for (int i = 0; i < amountParameters; ++i)
	{
		Parameter parameter(ByteArrayRead::ReadSizeAndString(device));
		parameter.SetName(ByteArrayRead::ReadSizeAndString(device));
		parameters.push_back(parameter);
	}
	code = ByteArrayRead::ReadSizeAndByteArray(device);
}

void OpMethod::ParseCode()
{
#ifdef _WIN32
	HANDLE writeBufferMethodCode;
	HANDLE readBufferMethodCode;
	CreatePipe(&readBufferMethodCode, &writeBufferMethodCode, 0, 0);
	WriteFile(writeBufferMethodCode, code.GetData(), code.size(), 0, 0);

	while (GetFileSize(readBufferMethodCode, 0) > 0)
	{
		Instruction instruction = static_cast<Instruction>(ByteArrayRead::ReadByte(readBufferMethodCode));
		ParseOpCode(instruction, readBufferMethodCode);
	}

#endif
	method->SetCode(methodCode);
}

void OpMethod::ParseOpCode(Instruction instruction, HANDLE& device)
{
	OpBase* op;
	switch (instruction)
	{
	case CALL_METHOD:
	{
		op = new OpCallm;
		break;
	}
	case PUSH_STR:
	{
		op = new OpPushStr;
		break;
	}
	case PUSH_INT32:
	{
		op = new OpPushInt32;
		break;
	}
	case RETURN:
	{
		op = new OpReturn;
		break;
	}
	case NEW:
	{
		op = new OpNew;
		break;
	}
	case SET:
	{
		op = new OpSet;
		break;
	}
	case GET:
	{
		op = new OpGet;
		break;
	}
	case LOCAL:
	{
		op = new OpLocal;
		break;
	}
	case DUP:
	{
		op = new OpDup;
		break;
	}
	case ADD:
	{
		op = new OpAdd;
		break;
	}
	case JMP:
	{
		op = new OpJmp;
		break;
	}
	case JMPIF:
	{
		op = new OpJmpif;
		break;
	}
	case GC:
	{
		op = new OpGc;
		break;
	}
	case NEWARR:
	{
		op = new OpNewarr;
		break;
	}
	case GETARR:
	{
		op = new OpGetarr;
		break;
	}
	case SETARR:
	{
		op = new OpSetarr;
		break;
	}
	case PUSH_BOOL:
	{
		op = new OpPushBool;
		break;
	}
	case PUSH_FLOAT:
	{
		op = new OpPushFloat;
		break;
	}
	case SUB:
	{
		op = new OpSub;
		break;
	}
	case MUL:
	{
		op = new OpMul;
		break;
	}
	case DIV:
	{
		op = new OpDiv;
		break;
	}
	case CAST:
	{
		op = new OpCast;
		break;
	}
	case MAX_STACK:
	{
		op = new OpMaxStack;
		break;
	}
	case REF:
	{
		op = new OpRef;
		break;
	}
	case DEREF:
	{
		op = new OpDeref;
		break;
	}
	case SETPD:
	{
		op = new OpSetpd;
		break;
	}
	default:
		Exit("Opcode not exists!");
	}

	op->Parse(device);
	methodCode.push_back(op);
}
