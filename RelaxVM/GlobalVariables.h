#pragma once
#include "Core/Frame.h"
#include "Core/Heap.h"
#include "Core/ClassList.h"
#include <stack>

struct GlobalVariables
{
	static inline String filename;
#ifdef _WIN32
	static inline HANDLE executableFile;
#endif
	static inline Class* mainClass = nullptr;
	static inline ClassList classes;
	static inline Heap heap = Heap(1000000);
	static inline std::stack<Frame*> frameStack;

	static inline const int version = 5;
	static inline const int opCodesForGC = 20;
};