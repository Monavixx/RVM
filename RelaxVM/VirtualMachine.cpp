#include "VirtualMachine.h"

VirtualMachine::VirtualMachine(const QStringList& argv) : arguments(argv)
{
	executableFile.setFileName(argv[1]);
}

VirtualMachine::~VirtualMachine()
{
	executableFile.close();
	qout << "Dest vir";
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
