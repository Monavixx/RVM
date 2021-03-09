#pragma once
#include "../Libs/ByteArrayLib.h"
#include "../GlobalVariables.h"

class OpBase
{
public:
	virtual void Run() = 0;
	virtual void Parse(HANDLE& device) = 0;
	void SetFrame(Frame* frame);
	Frame* GetFrame();

protected:
	Frame* frame = nullptr;
};

