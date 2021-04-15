#pragma once
#include "Core/Frame.h"
#include "Core/Heap.h"
#include "Core/NamespaceList.h"
#include <stack>
#include <fstream>

struct GlobalVariables
{
	static inline String filename;
	static inline String path;
	static inline std::ifstream executableFile;
	static inline Class* mainClass = nullptr;
	static inline NamespaceList namespaces;
	static inline Heap heap = Heap(1000000);
	static inline std::stack<Frame*> frameStack;

	static inline const int version = 2;
	static inline const int opCodesForGC = 20;
};