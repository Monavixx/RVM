#pragma once
#include <QtCore>

class VirtualMachine
{
public:
	VirtualMachine(QStringList& argv);
	void Start();

private:
	QStringList& argv;
};

