#include "VirtualMachine.h"

VirtualMachine::VirtualMachine()
{
	GlobalVariables::mainClass = nullptr;
	GlobalVariables::filename = Args::args[1];
}

VirtualMachine::~VirtualMachine()
{
#ifdef _WIN32
	CloseHandle(GlobalVariables::executableFile);
#endif
}

void VirtualMachine::Start()
{
#ifdef _WIN32
	GlobalVariables::executableFile = CreateFile(Args::args[1].toWCharArray(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
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

	for (auto& item : opCodes)
	{
		OpMethod* method = dynamic_cast<OpMethod*>(item);
		if (method != nullptr)
			method->ParseCode();
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

	clock_t start, end, ReResult;
	start = clock();
	ExecuteMethod();
	end = clock();
	ReResult = end - start;
	std::cout << "\n\n\nRelax: " << ReResult << "ms\n";
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
	default:
		Exit("Opcode not exists!");
	}

	op->Parse(GlobalVariables::executableFile);
	op->Run();
	opCodes.push_back(op);
}