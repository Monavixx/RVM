#pragma once
#include "../Libs/ByteArrayLib.h"
#include "../GlobalVariables.h"

class OpBase
{
public:
	virtual void Run() = 0;
	virtual void Parse(ifstream& device) = 0;
	inline void SetFrame(Frame* frame)
	{
		this->frame = frame;
	}
	inline Frame* GetFrame()
	{
		return frame;
	}


protected:
	Frame* frame = nullptr;
};

