#pragma once
#include <QtCore>

class Instruction
{
public:
	Instruction(const QString& name, const QString& args);
	QString name;
	QString args;
};

