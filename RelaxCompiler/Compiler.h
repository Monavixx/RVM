#pragma once
#include <QtCore>
#include "./ExitException.h"
#include "Exit.h"
#include "../Libs/ByteArrayLib.h"
#include "Element.h"

class Compiler
{
public:
	Compiler(const QStringList& argv);
	~Compiler();
	void Start();
	void StartCompiling(QIODevice& file);
	
private:
	QList<Element> elementList;
	QList<QString> keywords;
	QList<QString> operators;
	QStringList arguments;
	QString filename;
	QFile compilableFile;
};

