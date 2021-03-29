#include "OpGc.h"
#include "../Core/FieldObject.h"
#include "../Functions/GC.h"

void OpGc::Run()
{
	GC();
}

void OpGc::Parse(ifstream& device)
{
}
