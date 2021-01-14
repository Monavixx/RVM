#include "AsmCompiler.h"

AsmCompiler::AsmCompiler(const QStringList& arguments) : arguments(arguments)
{
	QString compilableFilename = arguments[1];
	QFile compilableFile(compilableFilename);
	if (!compilableFile.open(QIODevice::ReadOnly))
	{
		Exit("Error open file");
	}
	code = compilableFile.readAll();

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

	instructionsMethod["cmclass"] = [&](const QStringList& args) {CreateMainClass(args); };

}

AsmCompiler::~AsmCompiler()
{
	outputFile.close();
}

void AsmCompiler::Start()
{
	lines = code.split("\n");
	RemoveSpaces();

	QList<Instruction> instructions;
	for (auto& item : lines)
	{
		int indexOfSeparator = item.indexOf(' ');
		if (indexOfSeparator != -1)
		{
			QString name = item.mid(0, indexOfSeparator);
			QString args = item.mid(indexOfSeparator + 1, item.size() - indexOfSeparator - 1);
			instructions.push_back(Instruction(name, args));
		}
	}

	for (auto& item : instructions)
	{
		QStringList args;
		bool isOpenQuate = false;
		QString currentArg;
		for (int i = 0; i < item.args.size(); ++i)
		{
			if (item.args[i] == '\"')
				isOpenQuate = !isOpenQuate;
			else if (item.args[i] == ' ' && !isOpenQuate)
			{
				args.push_back(currentArg);
				currentArg = "";
			}
			currentArg.push_back(item.args[i]);
		}
		args.push_back(currentArg);

		if(instructionsMethod.contains(item.name))
			instructionsMethod[item.name](args);
	}
}

void AsmCompiler::RemoveSpaces()
{
	for (auto& item : lines)
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
	lines.removeAll("");
	lines.removeAll("\t");
}

void AsmCompiler::CreateMainClass(const QStringList& args)
{
	QString className = args[0];
	output << quint8(1) << className.toUtf8();
}
