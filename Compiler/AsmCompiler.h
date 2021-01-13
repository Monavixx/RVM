#pragma once
#include <QtCore>
#include "Exit.h"

class AsmCompiler
{
public:
	AsmCompiler(const QStringList& arguments);
	void Start();

private:
	QStringList arguments;
	QByteArray code;
	QFile outputFile;
	QDataStream output;
};

