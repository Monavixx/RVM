#pragma once
#include "Frame.h"
#include "Heap.h"
#include "ClassList.h"
struct GlobalVariables
{
	QString filename;
	QFile executableFile;
	Class* mainClass;
	ClassList classes;
	Heap heap;
	QStack<Frame*> frameStack;

	const int version = 3;
};