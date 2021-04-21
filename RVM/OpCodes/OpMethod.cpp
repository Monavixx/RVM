#include "OpMethod.h"
#include "../Core/FieldObject.h"

void OpMethod::Run()
{
	method = new Method(name, dataType, parameters, {}, accessModifier, isStatic);

	Namespace* declNamespace = GlobalVariables::namespaces[namespaceName];
	if (declNamespace == nullptr)
		Exit("method: namespace not found. Namespace: "_ss + namespaceName, 24);
	Class* _class = declNamespace->GetClass(declClassName);
	if (_class == nullptr)
	{
		Exit("method: class not found. Class: "_ss + declClassName, 25);
	}

	_class->AddMethod(method);
}

void OpMethod::Parse(ifstream& device)
{
	accessModifier = static_cast<AccessModifier>(ByteArrayRead::ReadByte(device));
	isStatic = ByteArrayRead::ReadByte(device);

	dataType = ByteArrayRead::ReadSizeAndString(device);
	namespaceName = ByteArrayRead::ReadSizeAndString(device);
	declClassName = ByteArrayRead::ReadSizeAndString(device);
	name = ByteArrayRead::ReadSizeAndString(device);

	size_t amountParameters = ByteArrayRead::ReadInt(device);

	for (size_t i = 0; i < amountParameters; ++i)
	{
		String namespaceName = ByteArrayRead::ReadSizeAndString(device);
		String className = ByteArrayRead::ReadSizeAndString(device);
		String name = ByteArrayRead::ReadSizeAndString(device);
		Parameter parameter(namespaceName, className, name);
		parameters.push_back(parameter);
	}
	sizeCode = ByteArrayRead::ReadInt(device);
	peekCode = device.tellg();
	device.seekg(sizeCode, std::ios_base::cur);
}

void OpMethod::ParseCode(ifstream& device)
{
	size_t endCodePeek = sizeCode + peekCode;
	device.seekg(peekCode, std::ios_base::beg);
	while (device.tellg() < endCodePeek)
	{
		Instruction instruction = static_cast<Instruction>(ByteArrayRead::ReadByte(device));
		ParseOpCode(instruction, device);
	}

	method->SetCode(methodCode);
}

void OpMethod::ParseOpCode(Instruction instruction, ifstream& device)
{
	OpBase* op = nullptr;
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
	case GETFIELD:
	{
		op = new OpGetfield;
		break;
	}
	case SETFIELD:
	{
		op = new OpSetfield;
		break;
	}
	case _THIS:
	{
		op = new OpThis;
		break;
	}
	case CE:
	{
		op = new OpCe;
		break;
	}
	case CL:
	{
		op = new OpCl;
		break;
	}
	case CB:
	{
		op = new OpCb;
		break;
	}
	case CLE:
	{
		op = new OpCle;
		break;
	}
	case CBE:
	{
		op = new OpCbe;
		break;
	}
	default:
		Exit("method: opcode not exists!", 26);
	}

	op->Parse(device);
	methodCode.push_back(op);
}
