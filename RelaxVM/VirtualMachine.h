#pragma once
#include <QtCore>

#include "../Libs/ByteArrayToNumber"
#include "../Libs/ConsoleTextStream.h"

class VirtualMachine
{
public:
	VirtualMachine(const QStringList& argv);
	~VirtualMachine();
	void Destructor();
	void Start();

private:
	QStringList arguments;
	QString filename;
	QFile executableFile;
	QDataStream fout;
};

