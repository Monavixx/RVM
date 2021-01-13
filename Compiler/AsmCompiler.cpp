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
		outputFilename = compilableFilename.split("." + QFileInfo(compilableFilename).suffix())[0] + ".rasm";
	}

	outputFile.setFileName(outputFilename);
	output.setDevice(&outputFile);
}

void AsmCompiler::Start()
{
}
