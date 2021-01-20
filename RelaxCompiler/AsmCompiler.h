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
	void RemoveSpaces(QStringList& code);
	quint8 AccessModifierToByte(const QString& accessModifier);
	quint8 IsStaticToByte(const QString& isStatic);
	quint8 StdToByte(const QString& std);
	QStringList CreateCodeFromString(const QString& stringCode);
	QList<Instruction> CreateInstructionsFromCode(const QStringList& code);
	void ExecuteCode(const QList<Instruction>& instructions, QDataStream& dataStream);

	void CreateMainClass(const QStringList& args, QDataStream& dataStream);
	void CreateMethod(const QStringList& args, QDataStream& dataStream);
	void PushStr(const QStringList& args, QDataStream& dataStream);
	void CallMethod(const QStringList& args, QDataStream& dataStream);

private:
	QStringList arguments;
	QString allCode;
	QFile outputFile;
	QDataStream output;
	//QStringList lines;

	QMap<QString, std::function<void (const QStringList&, QDataStream&)>> instructionsMethod;
};

