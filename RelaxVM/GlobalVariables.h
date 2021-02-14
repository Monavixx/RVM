#pragma once
#include "Core/Frame.h"
#include "Core/Heap.h"
#include "Core/ClassList.h"

struct GlobalVariables
{
	QString filename;
	QFile executableFile;
	Class* mainClass;
	ClassList classes;
	Heap heap;
	QStack<Frame*> frameStack;

	const int version = 4;
};