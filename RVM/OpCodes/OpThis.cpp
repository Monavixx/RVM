#include "OpThis.h"
#include "../Core/FieldObject.h"

void OpThis::Run()
{
	frame->GetStack().push(frame->AddValue(new Value(ValueType::OBJECT,  UValue(frame->GetObjectThis()))));
}

void OpThis::Parse(ifstream& device)
{
}
