#include "OpMethod.h"

void OpMethod::Run()
{
	Method* method = new Method(name, dataType, declClassName, parameters, methodCode, accessModifier, isStatic);

	Class* _class = GlobalVariables::classes.FindClassByName(declClassName);
	if (_class == nullptr)
	{
		Exit("method: decl class not found");
	}

	_class->AddMethod(method);
}

void OpMethod::Parse(QIODevice& device)
{
	accessModifier = static_cast<AccessModifier>(ByteArrayRead::ReadByte(device));
	isStatic = ByteArrayRead::ReadByte(device);

	dataType = ByteArrayRead::ReadSizeAndString(device);
	declClassName = ByteArrayRead::ReadSizeAndString(device);
	name = ByteArrayRead::ReadSizeAndString(device);

	int amountParameters = ByteArrayRead::ReadInt(device);

	for (int i = 0; i < amountParameters; ++i)
	{
		QString parameterDataType = ByteArrayRead::ReadSizeAndString(device);
		QString parameterName = ByteArrayRead::ReadSizeAndString(device);
		Parameter parameter(parameterDataType);
		parameter.SetName(parameterName);
		parameters.push_back(parameter);
	}
	QByteArray code = ByteArrayRead::ReadSizeAndByteArray(device);
	QBuffer buffer(&code);
	buffer.open(QIODevice::ReadOnly);

	while (buffer.bytesAvailable() > 0)
	{
		Instruction instruction = static_cast<Instruction>(ByteArrayRead::ReadByte(buffer));
		ParseOpCode(instruction, buffer);
	}
}

void OpMethod::ParseOpCode(Instruction instruction, QIODevice& device)
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
	default:
		Exit("Opcode not exists!");
	}

	op->Parse(device);
	methodCode.push_back(op);
}
