#pragma once
#include "Core/Frame.h"
#include "Core/Heap.h"
#include "Core/ClassList.h"

struct GlobalVariables
{
	static inline QString filename;
	static inline QFile executableFile;
	static inline Class* mainClass = nullptr;
	static inline ClassList classes;
	static inline Heap heap = Heap(10000);
	static inline QStack<Frame*> frameStack;

	static inline const int version = 4;
	static inline const int opCodesForGC = 20;
};