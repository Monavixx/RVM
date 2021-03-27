#include "OpPushFloat.h"
#include "../Core/FieldObject.h"

void OpPushFloat::Run()
{
	frame->GetStack().push(frame->AddValue(new Value(ValueType::FLOAT, UValue{ .fnum = data })));
}

void OpPushFloat::Parse(HANDLE& device)
{
	data = ByteArrayRead::ReadFloat(device);
}
