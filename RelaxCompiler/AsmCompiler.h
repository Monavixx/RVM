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
	QStringList StringToSignature(const QString& strSignature);
	int ProcessSizeInstructions(const QList<Instruction>& instructions);

	void CreateMainClass(const QStringList& args, QDataStream& dataStream);
	void CreateMethod(const QStringList& args, QDataStream& dataStream);
	void PushStr(const QStringList& args, QDataStream& dataStream);
	void CallMethod(const QStringList& args, QDataStream& dataStream);
	void New(const QStringList& args, QDataStream& dataStream);
	void CreateClass(const QStringList& args, QDataStream& dataStream);
	void Get(const QStringList& args, QDataStream& dataStream);
	void Set(const QStringList& args, QDataStream& dataStream);
	void Local(const QStringList& args, QDataStream& dataStream);
	void Gc(const QStringList& args, QDataStream& dataStream);
	void PushInt32(const QStringList& args, QDataStream& dataStream);
	void Return(const QStringList& args, QDataStream& dataStream);
	void Add(const QStringList& args, QDataStream& dataStream);
	void Dup(const QStringList& args, QDataStream& dataStream);
	void Jmp(const QStringList& args, QDataStream& dataStream);
	void Jmpif(const QStringList& args, QDataStream& dataStream);

private:
	QStringList arguments;
	QString allCode;
	QFile outputFile;
	QDataStream output;
	QMap<QString, std::function<int (const QStringList&, QDataStream&)>> instructionsMethod;
	QMap<QString, int> tagsCurrentMethod;
	int sizeCurrentMethod = 0;
};

