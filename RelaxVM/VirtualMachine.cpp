#include "VirtualMachine.h"

VirtualMachine::VirtualMachine(const QStringList& argv) : arguments(argv), fout(&executableFile)
{
	filename = argv[1];
	executableFile.setFileName(filename);
}

VirtualMachine::~VirtualMachine()
{
	Destructor();
}

void VirtualMachine::Destructor()
{
	executableFile.close();
}

void VirtualMachine::Start()
{
	if (!executableFile.open(QIODevice::ReadOnly))
	{
		qout << "File open error!";
		exit(0);
	}
}
