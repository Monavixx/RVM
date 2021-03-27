#include "OpPushBool.h"
#include "../Core/FieldObject.h"

void OpPushBool::Run()
{
	frame->GetStack().push(frame->AddValue(new Value(ValueType::BOOL, UValue{ .boolean = data })));
}

void OpPushBool::Parse(HANDLE& device)
{
	data = (bool)ByteArrayRead::ReadByte(device);
}
