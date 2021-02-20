#include "VirtualMachine.h"

VirtualMachine::VirtualMachine()
{
	GlobalVariables::mainClass = nullptr;
	GlobalVariables::filename = Args::args[1];
	GlobalVariables::executableFile.setFileName(GlobalVariables::filename);
}

VirtualMachine::~VirtualMachine()
{
	GlobalVariables::executableFile.close();

	for (auto& item : GlobalVariables::heap)
	{
		if(item != nullptr)
			delete item;
	}
	
}

void VirtualMachine::Start()
{
	if (!GlobalVariables::executableFile.open(QIODevice::ReadOnly))
	{
		Exit("File open error!");
	}

	int versionCode = ByteArrayRead::ReadInt(GlobalVariables::executableFile);
	if (versionCode != GlobalVariables::version)
		Exit("version " + QString::number(GlobalVariables::version) + " is required to run this code");

	while (GlobalVariables::executableFile.bytesAvailable() > 0)
	{
		Instruction instruction = static_cast<Instruction>(ByteArrayRead::ReadByte(GlobalVariables::executableFile));
		ParseCode(instruction);
	}
	for (auto& item : opCodes)
	{
		delete item;
	}
	opCodes.clear();

	if (GlobalVariables::mainClass == nullptr)
	{
		Exit("main class not found");
	}

	Method* mainMethod = GlobalVariables::mainClass->GetMethod("Main", {});
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
	OpBase* op;
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