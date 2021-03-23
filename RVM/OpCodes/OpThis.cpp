#include "OpThis.h"

void OpThis::Run()
{
	frame->GetStack().push(frame->GetObjectThis());
}

void OpThis::Parse(HANDLE& device)
{
}
