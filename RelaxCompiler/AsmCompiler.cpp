#include "AsmCompiler.h"

AsmCompiler::AsmCompiler(const QStringList& arguments) : arguments(arguments)
{
	QString compilableFilename = arguments[1];
	QFile compilableFile(compilableFilename);
	if (!compilableFile.open(QIODevice::ReadOnly))
	{
		Exit("Error open file");
	}
	allCode = compilableFile.readAll();

	QString outputFilename;
	if (arguments.contains("-o"))
	{
		if (arguments.size() > arguments.indexOf("-o") + 1)
		{
			outputFilename = arguments[arguments.indexOf("-o") + 1];
		}
		else
		{
			Exit("After the -o flag a filename was expected");
		}
	}
	else
	{
		QFileInfo info(compilableFile);
		outputFilename = info.path() + "/" + info.completeBaseName() + ".ree";
	}

	outputFile.setFileName(outputFilename);
	output.setDevice(&outputFile);

	if (!outputFile.open(QIODevice::WriteOnly))
	{
		Exit("Error open file");
	}

	instructionsMethod["cmclass"] = [&](const QStringList& args, QDataStream& dataStream) {CreateMainClass(args, dataStream); };
	instructionsMethod["method"] = [&](const QStringList& args, QDataStream& dataStream) {CreateMethod(args, dataStream); };
	instructionsMethod["push.str"] = [&](const QStringList& args, QDataStream& dataStream) {PushStr(args, dataStream); };
	instructionsMethod["callm"] = [&](const QStringList& args, QDataStream& dataStream) {CallMethod(args, dataStream); };

}

AsmCompiler::~AsmCompiler()
{
	outputFile.close();
}

void AsmCompiler::Start()
{
	QStringList code = CreateCodeFromString(allCode);

	QList<Instruction> instructions = CreateInstructionsFromCode(code);

	ExecuteCode(instructions, output);
}

void AsmCompiler::RemoveSpaces(QStringList& code)
{
	code.removeAll("");
	for (auto& item : code)
	{
		bool isPartMethod = item[0] == "\t";
		item.replace(QRegExp("[ \f\t\v\u00A0]+"), " ");
		item.remove('\n');
		item.remove('\r');
		if (isPartMethod)
		{
			item.remove(0, 1);
			item.push_front("\t");
		}
	}
	code.removeAll("");
	code.removeAll("\t");
}

quint8 AsmCompiler::AccessModifierToByte(const QString& accessModifier)
{
	static QHash<QString, quint8> accessModifiers = {
		{"private", 0},
		{"public", 1},
		{"protected", 2}
	};
	return accessModifiers[accessModifier];
}

quint8 AsmCompiler::IsStaticToByte(const QString& isStatic)
{
	static QHash<QString, quint8> isStatics = {
		{"instance", 0},
		{"static", 1}
	};
	return isStatics[isStatic];
}

quint8 AsmCompiler::StdToByte(const QString& std)
{
	static QHash<QString, quint8> stds = {
		{"std", 1},
		{"usr", 0}
	};
	return stds[std];
}

QStringList AsmCompiler::CreateCodeFromString(const QString& stringCode)
{
	QStringList code = stringCode.split("\n");
	RemoveSpaces(code);
	for (auto& item : code)
	{
		item.replace(", ", ",");
	}
	return code;
}

QList<Instruction> AsmCompiler::CreateInstructionsFromCode(const QStringList& code)
{
	QList<Instruction> instructions;
	for (auto& item : code)
	{
		int indexOfSeparator = item.indexOf(' ');
		if (indexOfSeparator != -1)
		{
			QString name = item.mid(0, indexOfSeparator);
			QString args = item.mid(indexOfSeparator + 1, item.size() - indexOfSeparator - 1);
			instructions.push_back(Instruction(name, args));
		}
	}
	return instructions;
}

void AsmCompiler::ExecuteCode(const QList<Instruction>& instructions, QDataStream& dataStream)
{
	for (int i = 0; i < instructions.size(); ++i)
	{
		QStringList args;
		QString instructionName = instructions[i].name;
		bool isOpenQuate = false;
		QString currentArg;
		for (int j = 0; j < instructions[i].args.size(); ++j)
		{
			if (instructions[i].args[j] == '\"')
			{
				isOpenQuate = !isOpenQuate;
				currentArg.push_back(instructions[i].args[j]);
			}
			else if (instructions[i].args[j] == ' ' && !isOpenQuate)
			{
				args.push_back(currentArg);
				currentArg = "";
			}
			else
			{
				currentArg.push_back(instructions[i].args[j]);
			}
		}
		bool isHasCode = currentArg.back() == ':';
		args.push_back(isHasCode ? currentArg.mid(0, currentArg.size() - 1) : currentArg);

		QString code;
		if (isHasCode)
		{
			++i;
			while (true)
			{
				if (instructions.size() - 1 >= i)
				{
					if (instructions[i].name[0] == '\t')
					{
						code += instructions[i].name.mid(1) + " " + instructions[i].args + "\n";
						++i;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}

		args.push_back(code);
		if (instructionsMethod.contains(instructionName))
			instructionsMethod[instructionName](args, dataStream);
	}
}

void AsmCompiler::CreateMainClass(const QStringList& args, QDataStream& dataStream)
{
	QString className = args[0];
	dataStream << quint8(1) << className.toUtf8();
}

void AsmCompiler::CreateMethod(const QStringList& args, QDataStream& dataStream)
{
	QString accessModidfier = args[0];
	QString isStatic = args[1];
	QString dataType = args[2];
	QString signature = args[3];
	QString code = args[4];

	QString className;
	QString methodName;
	QStringList parameters;

	int indexOfParameters = signature.indexOf("(");

	if (indexOfParameters == -1)
		Exit("Error create method");

	QString stringParameters = signature.mid(indexOfParameters + 1, signature.size() - indexOfParameters - 2);
	int indexOfStartMethodName = signature.mid(0, indexOfParameters).lastIndexOf(".") + 1;

	if (indexOfStartMethodName == -1)
		Exit("Error create method");

	className = signature.mid(0, indexOfStartMethodName - 1);
	methodName = signature.mid(indexOfStartMethodName, indexOfParameters - indexOfStartMethodName);
	
	QString currentParameter;
	for (int i = 0; i < stringParameters.size(); ++i)
	{
		if (stringParameters[i] == ',')
		{
			parameters.push_back(currentParameter);
			currentParameter = "";
		}
		else
		{
			currentParameter.push_back(stringParameters[i]);
		}
	}
	if (!currentParameter.isEmpty())
	{
		parameters.push_back(currentParameter);
	}


	dataStream << quint8(4) << AccessModifierToByte(accessModidfier) << IsStaticToByte(isStatic) << dataType.toUtf8() << className.toUtf8() << methodName.toUtf8() << int(parameters.size());
	for (auto& item : parameters)
	{
		dataStream << item.toUtf8();
	}

	QByteArray byteArrayMethodCode;
	QDataStream dsMethodCode(&byteArrayMethodCode, QIODevice::WriteOnly);
	QStringList methodCode = CreateCodeFromString(code);
	QList<Instruction> methodInstructions = CreateInstructionsFromCode(methodCode);
	ExecuteCode(methodInstructions, dsMethodCode);
	
	dataStream << byteArrayMethodCode;
}

void AsmCompiler::PushStr(const QStringList& args, QDataStream& dataStream)
{
	dataStream << quint8(7) << args[0].mid(1, args[0].size() - 2).toUtf8();
}

void AsmCompiler::CallMethod(const QStringList& args, QDataStream& dataStream)
{
	dataStream << quint8(5)
		<< StdToByte(args[0])
		<< IsStaticToByte(args[1])
		<< args[2].toUtf8();

	QString signature = args[3];
	QString className;
	QString methodName;
	QStringList parameters;

	int indexOfParameters = signature.indexOf("(");

	if (indexOfParameters == -1)
		Exit("Error call method");

	QString stringParameters = signature.mid(indexOfParameters + 1, signature.size() - indexOfParameters - 2);
	int indexOfStartMethodName = signature.mid(0, indexOfParameters).lastIndexOf(".") + 1;

	if (indexOfStartMethodName == -1)
		Exit("Error call method");

	className = signature.mid(0, indexOfStartMethodName - 1);
	methodName = signature.mid(indexOfStartMethodName, indexOfParameters - indexOfStartMethodName);

	QString currentParameter;
	for (int i = 0; i < stringParameters.size(); ++i)
	{
		if (stringParameters[i] == ',')
		{
			parameters.push_back(currentParameter);
			currentParameter = "";
		}
		else
		{
			currentParameter.push_back(stringParameters[i]);
		}
	}
	if (!currentParameter.isEmpty())
	{
		parameters.push_back(currentParameter);
	}

	dataStream << className.toUtf8() << methodName.toUtf8() << int(parameters.size());
	for (auto& item : parameters)
	{
		dataStream << item.toUtf8();
	}
}
