#pragma once
#include <QtCore>
#include "Exit.h"
#include "../Libs/ConsoleTextStream.h"
#include "Instruction.h"

class AsmCompiler
{
public:
	AsmCompiler(const QStringList& arguments);
	~AsmCompiler();
	void Start();
	void RemoveSpaces();

	void CreateMainClass(const QStringList& args);

private:
	QStringList arguments;
	QString code;
	QFile outputFile;
	QDataStream output;
	QStringList lines;


	QMap<QString, std::function<void (const QStringList&)>> instructionsMethod;
};

