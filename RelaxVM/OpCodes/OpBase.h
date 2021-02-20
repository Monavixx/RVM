#pragma once
#include "../Libs/ByteArrayLib.h"
#include "../GlobalVariables.h"

class OpBase
{
public:
	virtual void Run() = 0;
	virtual void Parse(QIODevice& device) = 0;
	void SetFrame(Frame* frame);
	Frame* GetFrame();

protected:
	Frame* frame = nullptr;
};

