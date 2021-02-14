#include "VirtualMachine.h"

VirtualMachine::VirtualMachine() : gv(new GlobalVariables)
{
	gv->mainClass = nullptr;
	gv->filename = Args::args[1];
	gv->executableFile.setFileName(gv->filename);
}

VirtualMachine::~VirtualMachine()
{
	gv->executableFile.close();

	for (auto& item : gv->heap)
	{
		if(item != nullptr)
			delete item;
	}
	
}

void VirtualMachine::Start()
{
	if (!gv->executableFile.open(QIODevice::ReadOnly))
	{
		Exit("File open error!");
	}

	int versionCode = ByteArrayRead::ReadInt(gv->executableFile);
	if (versionCode != gv->version)
		Exit("version " + QString::number(gv->version) + " is required to run this code");

	while (gv->executableFile.bytesAvailable() > 0)
	{
		Instruction instruction = static_cast<Instruction>(ByteArrayRead::ReadByte(gv->executableFile));
		ParseCode(instruction);
	}

	if (gv->mainClass == nullptr)
	{
		Exit("main class not found");
	}

	Method* mainMethod = gv->mainClass->GetMethod("Main", {});
	Frame* frame = new Frame(mainMethod);
	gv->frameStack.push(frame);

	clock_t start, end, ReResult;
	start = clock();
	ExecuteMethod(gv);
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

	op->SetGlobalVariables(gv);
	op->Parse(gv->executableFile);
	op->Run();
	opCodes.push_back(op);
}