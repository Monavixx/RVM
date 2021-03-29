#pragma once
#include "Core/Frame.h"
#include "Core/Heap.h"
#include "Core/ClassList.h"
#include <stack>
#include <fstream>

struct GlobalVariables
{
	static inline String filename;
	static inline std::ifstream executableFile;
	static inline Class* mainClass = nullptr;
	static inline ClassList classes;
	static inline Heap heap = Heap(1000000);
	static inline std::stack<Frame*> frameStack;

	static inline const int version = 6;
	static inline const int opCodesForGC = 20;
};