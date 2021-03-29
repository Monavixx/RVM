#include "OpPushBool.h"
#include "../Core/FieldObject.h"

void OpPushBool::Run()
{
	frame->GetStack().push(frame->AddValue(new Value(ValueType::BOOL, UValue(data))));
}

void OpPushBool::Parse(ifstream& device)
{
	data = (bool)ByteArrayRead::ReadByte(device);
}
