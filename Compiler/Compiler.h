#pragma once
#include <QtCore>
#include "./ExitException.h"
#include "Exit.h"


class Compiler
{
public:
	Compiler(const QStringList& argv);
	~Compiler();
	void Start();
	
private:
	QStringList agruments;
	QString filename;
	QFile compilableFile;
};

