#pragma once
#include <QtCore>

#include "../Libs/ByteArrayLib.h"
#include "../Libs/ConsoleTextStream.h"
#include "Exceptions/ExitException.h"
#include "Functions/Exit.h"

class VirtualMachine
{
public:
	VirtualMachine(const QStringList& argv);
	~VirtualMachine();
	
	void Start();
	void ProcessInstruction(quint8 instruction);

private:
	QStringList arguments;
	QString filename;
	QFile executableFile;
};

