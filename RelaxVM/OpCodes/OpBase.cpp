#include "OpBase.h"

void OpBase::SetFrame(Frame* frame)
{
	this->frame = frame;
}

void OpBase::SetGlobalVariables(GlobalVariables* globalVariables)
{
	this->gv = globalVariables;
}

GlobalVariables* OpBase::GetGlobalVariables()
{
	return gv;
}

Frame* OpBase::GetFrame()
{
	return frame;
}
