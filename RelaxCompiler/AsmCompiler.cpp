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



	instructionsMethod["mclass"] = [&](const QStringList& args, QDataStream& dataStream)->int {CreateMainClass(args, dataStream); return 0; };

	instructionsMethod["new"] = [&](const QStringList& args, QDataStream& dataStream)->int {
		int before = dataStream.device()->size();
		New(args, dataStream);
		return dataStream.device()->size() - before;
	};

	instructionsMethod["class"] = [&](const QStringList& args, QDataStream& dataStream)->int {CreateClass(args, dataStream); return 0; };

	instructionsMethod["method"] = [&](const QStringList& args, QDataStream& dataStream)->int {CreateMethod(args, dataStream); return 0; };

	instructionsMethod["callm"] = [&](const QStringList& args, QDataStream& dataStream)->int {
		int before = dataStream.device()->size();
		CallMethod(args, dataStream);
		return dataStream.device()->size() - before;
	};

	instructionsMethod["get"] = [&](const QStringList& args, QDataStream& dataStream)->int {
		int before = dataStream.device()->size();
		Get(args, dataStream);
		return dataStream.device()->size() - before;
	};

	instructionsMethod["push.str"] = [&](const QStringList& args, QDataStream& dataStream)->int{
		int before = dataStream.device()->size();
		PushStr(args, dataStream);
		return dataStream.device()->size() - before;
	};
	
	instructionsMethod["push.int32"] = [&](const QStringList& args, QDataStream& dataStream)->int {
		int before = dataStream.device()->size();
		PushInt32(args, dataStream);
		return dataStream.device()->size() - before;
	};

	instructionsMethod["return"] = [&](const QStringList& args, QDataStream& dataStream)->int {
		int before = dataStream.device()->size();
		Return(args, dataStream);
		return dataStream.device()->size() - before;
	};

	instructionsMethod["set"] = [&](const QStringList& args, QDataStream& dataStream)->int {
		int before = dataStream.device()->size();
		Set(args, dataStream);
		return dataStream.device()->size() - before;
	};
	
	instructionsMethod["local"] = [&](const QStringList& args, QDataStream& dataStream)->int {
		int before = dataStream.device()->size();
		Local(args, dataStream);
		return dataStream.device()->size() - before;
	};

	instructionsMethod["add"] = [&](const QStringList& args, QDataStream& dataStream)->int {
		int before = dataStream.device()->size();
		Add(args, dataStream);
		return dataStream.device()->size() - before;
	};

	instructionsMethod["dup"] = [&](const QStringList& args, QDataStream& dataStream)->int {
		int before = dataStream.device()->size();
		Dup(args, dataStream);
		return dataStream.device()->size() - before;
	};

	instructionsMethod["jmp"] = [&](const QStringList& args, QDataStream& dataStream)->int {
		int before = dataStream.device()->size();
		Jmp(args, dataStream);
		return dataStream.device()->size() - before;
	};

	instructionsMethod["jmpif"] = [&](const QStringList& args, QDataStream& dataStream)->int {
		int before = dataStream.device()->size();
		Jmpif(args, dataStream);
		return dataStream.device()->size() - before;
	};

	instructionsMethod["gc"] = [&](const QStringList& args, QDataStream& dataStream)->int {
		int before = dataStream.device()->size();
		Gc(args, dataStream);
		return dataStream.device()->size() - before;
	};

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
		else
		{
			instructions.push_back(Instruction(item, ""));
		}
	}
	return instructions;
}

void AsmCompiler::ExecuteCode(const QList<Instruction>& instructions, QDataStream& dataStream)
{
	for (int i = 0; i < instructions.size(); ++i)
	{
		sizeCurrentMethod += ProcessSizeInstructions({ instructions[0] });

		QStringList args;
		QString instructionName = instructions[i].name;
		bool isOpenQuote = false;
		QString currentArg;
		for (int j = 0; j < instructions[i].args.size(); ++j)
		{
			if (instructions[i].args[j] == '\"')
			{
				isOpenQuote = !isOpenQuote;
				currentArg.push_back(instructions[i].args[j]);
			}
			else if (instructions[i].args[j] == ' ' && !isOpenQuote)
			{
				args.push_back(currentArg);
				currentArg = "";
			}
			else
			{
				currentArg.push_back(instructions[i].args[j]);
			}
		}

		if (currentArg == "" && args.isEmpty() && instructionName.back() == ':')
		{
			tagsCurrentMethod[instructionName.mid(0, instructionName.size() - 1)] = sizeCurrentMethod;
		}
	}
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
		bool isHasCode = false;
		if (!(currentArg == "" && args.isEmpty()))
		{
			isHasCode = currentArg.back() == ':';
			args.push_back(isHasCode ? currentArg.mid(0, currentArg.size() - 1) : currentArg);
		}

		if (isHasCode)
		{
			QString code;
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
			args.push_back(code);
		}

		if (instructionsMethod.contains(instructionName))
		{
			sizeCurrentMethod += instructionsMethod[instructionName](args, dataStream);
		}
	}
}

QStringList AsmCompiler::StringToSignature(const QString& strSignature)
{
	QString className;
	QString methodName;
	QStringList parameters;

	int indexOfParameters = strSignature.indexOf("(");

	if (indexOfParameters == -1)
		Exit("Error call method");

	QString stringParameters = strSignature.mid(indexOfParameters + 1, strSignature.size() - indexOfParameters - 2);
	int indexOfStartMethodName = strSignature.mid(0, indexOfParameters).lastIndexOf(".") + 1;

	if (indexOfStartMethodName == -1)
		Exit("Error call method");

	className = strSignature.mid(0, indexOfStartMethodName - 1);
	methodName = strSignature.mid(indexOfStartMethodName, indexOfParameters - indexOfStartMethodName);

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

	return QStringList{className, methodName} + parameters;
}

int AsmCompiler::ProcessSizeInstructions(const QList<Instruction>& instructions)
{
	QByteArray code;
	QDataStream ds(&code, QIODevice::WriteOnly);


	return code.size();
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
	QString strSignature = args[3];
	QString code = args[4];


	QStringList signature = StringToSignature(strSignature);
	QString className = signature[0];
	QString methodName = signature[1];
	QStringList parameters = signature.mid(2);


	dataStream << quint8(4) << AccessModifierToByte(accessModidfier) << IsStaticToByte(isStatic) << dataType.toUtf8() << className.toUtf8() << methodName.toUtf8() << int(parameters.size());
	for (auto& item : parameters)
	{
		dataStream << item.toUtf8();
	}
	sizeCurrentMethod = 0;

	QByteArray byteArrayMethodCode;
	QDataStream dsMethodCode(&byteArrayMethodCode, QIODevice::WriteOnly);
	QStringList methodCode = CreateCodeFromString(code);
	QList<Instruction> methodInstructions = CreateInstructionsFromCode(methodCode);
	ExecuteCode(methodInstructions, dsMethodCode);
	
	dataStream << byteArrayMethodCode;
}

void AsmCompiler::PushStr(const QStringList& args, QDataStream& dataStream)
{
	dataStream << quint8(7) << args[0].mid(1, args[0].size() - 2).replace("\\n", "\n").replace("\\t", "\t").toUtf8();
}

void AsmCompiler::CallMethod(const QStringList& args, QDataStream& dataStream)
{
	dataStream << quint8(5)
		<< StdToByte(args[0])
		<< IsStaticToByte(args[1])
		<< args[2].toUtf8();


	QString strSignature = args[3];
	QStringList signature = StringToSignature(strSignature);
	QString className = signature[0];
	QString methodName = signature[1];
	QStringList parameters = signature.mid(2);

	dataStream << className.toUtf8() << methodName.toUtf8() << int(parameters.size());
	for (auto& item : parameters)
	{
		dataStream << item.toUtf8();
	}
}

void AsmCompiler::New(const QStringList& args, QDataStream& dataStream)
{
	dataStream << quint8(2) << IsStaticToByte(args[0]);

	QString strSignature = args[1];
	QString className;
	QStringList parameters;

	int indexOfParameters = strSignature.indexOf("(");

	if (indexOfParameters == -1)
		Exit("Error call method");

	QString stringParameters = strSignature.mid(indexOfParameters + 1, strSignature.size() - indexOfParameters - 2);

	className = strSignature.mid(0, indexOfParameters);

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

	dataStream << className.toUtf8();
	for (auto& item : parameters)
	{
		dataStream << item.toUtf8();
	}
}

void AsmCompiler::CreateClass(const QStringList& args, QDataStream& dataStream)
{
	dataStream << quint8(3) << args[0].toUtf8();
}

void AsmCompiler::Get(const QStringList& args, QDataStream& dataStream)
{
	int id = args[0].toInt();
	dataStream << quint8(6) << id;
}

void AsmCompiler::Set(const QStringList& args, QDataStream& dataStream)
{
	int id = args[0].toInt();
	dataStream << quint8(10) << id;
}

void AsmCompiler::Local(const QStringList& args, QDataStream& dataStream)
{
	int id = args[0].toInt();
	dataStream << quint8(11) << id;
}

void AsmCompiler::Gc(const QStringList& args, QDataStream& dataStream)
{
	dataStream << quint8(16);
}

void AsmCompiler::PushInt32(const QStringList& args, QDataStream& dataStream)
{
	int value = args[0].toInt();
	dataStream << quint8(8) << value;
}

void AsmCompiler::Return(const QStringList& args, QDataStream& dataStream)
{
}

void AsmCompiler::Add(const QStringList& args, QDataStream& dataStream)
{
	dataStream << quint8(12);
}

void AsmCompiler::Dup(const QStringList& args, QDataStream& dataStream)
{
	dataStream << quint8(13);
}

void AsmCompiler::Jmp(const QStringList& args, QDataStream& dataStream)
{
	dataStream << quint8(14) << tagsCurrentMethod[args[0]];
}

void AsmCompiler::Jmpif(const QStringList& args, QDataStream& dataStream)
{
	dataStream << quint8(15) << tagsCurrentMethod[args[0]];
}
