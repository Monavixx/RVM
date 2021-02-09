#pragma once
#include "Frame.h"
#include "Heap.h"
#include "ClassList.h"
#include <stack>
struct GlobalVariables
{
	QString filename;
	QFile executableFile;
	Class* mainClass;
	ClassList classes;
	Heap heap;
	std::stack<Frame*> frameStack;

	const int version = 3;
};