#include "VirtualMachine.h"
#include "Core/FieldObject.h"

VirtualMachine::VirtualMachine()
{
	GlobalVariables::mainClass = nullptr;
	GlobalVariables::filename = Args::args[1];
}

VirtualMachine::~VirtualMachine()
{
#ifdef _WIN321
	CloseHandle(GlobalVariables::executableFile);
#else
	GlobalVariables::executableFile.close();
#endif
}

void VirtualMachine::Start()
{
#ifdef _WIN32
	GlobalVariables::executableFile.open(Args::args[1].toStdString(), std::ios::in | std::ios::binary);
#else
	GlobalVariables::executableFile.open(Args::args[1], std::ios::in | std::ios::binary);
#endif
	int versionCode = ByteArrayRead::ReadInt(GlobalVariables::executableFile);
	if (versionCode != GlobalVariables::version)
		Exit("version " + std::to_string(GlobalVariables::version) + " is required to run this code");
	
	GlobalVariables::classes.CreateStdClasses();

	Instruction instruction = static_cast<Instruction>(ByteArrayRead::ReadByte(GlobalVariables::executableFile));
	while (instruction != 0)
	{
		ParseCode(instruction);
		instruction = static_cast<Instruction>(ByteArrayRead::ReadByte(GlobalVariables::executableFile));
	}

	GlobalVariables::executableFile.clear();
	int a = GlobalVariables::executableFile.tellg();

	for (auto& item : opCodes)
	{
		OpMethod* method = dynamic_cast<OpMethod*>(item);
		if (method != nullptr)
			method->ParseCode(GlobalVariables::executableFile);
		delete item;
	}
	opCodes.clear();

	if (GlobalVariables::mainClass == nullptr)
	{
		Exit("main class not found");
	}

	IMethod* mainMethod = GlobalVariables::mainClass->GetMethod("Main", {});
	Frame* frame = new Frame(mainMethod);
	GlobalVariables::frameStack.push(frame);

#ifdef _DEBUG
	clock_t start, end, ReResult;
	start = clock();
#endif
	ExecuteMethod();
#ifdef _DEBUG
	end = clock();
	ReResult = end - start;
	std::cout << "\n\n\nRelax: " << ReResult << "ms\n";
#endif
}

void VirtualMachine::ParseCode(Instruction instruction)
{
	OpBase* op = nullptr;
	switch (instruction)
	{
	case CREATE_MAIN_CLASS:
	{
		op = new OpMclass;
		break;
	}
	case CREATE_CLASS:
	{
		op = new OpClass;
		break;
	}
	case CREATE_METHOD:
	{
		op = new OpMethod;
		break;
	}
	case FIELD:
	{
		op = new OpField;
		break;
	}
	default:
		Exit("Opcode not exists!");
	}

	op->Parse(GlobalVariables::executableFile);
	op->Run();
	opCodes.push_back(op);
}