#include "OpBase.h"

void OpBase::SetFrame(Frame* frame)
{
	this->frame = frame;
}

Frame* OpBase::GetFrame()
{
	return frame;
}
