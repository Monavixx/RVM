#pragma once
#include "ByteArrayLib.h"
#include "GlobalVariables.h"

class OpBase
{
public:
	virtual void Run() = 0;
	virtual void Parse(QIODevice& device) = 0;
	void SetFrame(Frame* frame);
	void SetGlobalVariables(GlobalVariables* globalVariables);
	GlobalVariables* GetGlobalVariables();
	Frame* GetFrame();

protected:
	Frame* frame = nullptr;
	GlobalVariables* gv = nullptr;
};

