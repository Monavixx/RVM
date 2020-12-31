#include "VirtualMachine.h"

VirtualMachine::VirtualMachine(const QStringList& argv) : arguments(argv)
{
	filename = argv[1];
	executableFile.setFileName(filename);
}

VirtualMachine::~VirtualMachine()
{
	Destructor();
	qout << "Dest vir";
}

void VirtualMachine::Destructor()
{
	executableFile.close();
}

void VirtualMachine::Start()
{
	if (!executableFile.open(QIODevice::ReadOnly))
	{
		Exit("File open error!");
	}

	while (executableFile.bytesAvailable() > 0)
	{
		quint8 instruction = ByteArrayConvert::byteArrayToByte(executableFile.read(1));
		ProcessInstruction(instruction);
	}
}

void VirtualMachine::ProcessInstruction(quint8 instruction)
{
	switch (instruction)
	{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
	}
}
