#include "OpPushInt32.h"
#include "../Core/FieldObject.h"

void OpPushInt32::Run()
{
	frame->GetStack().push(frame->AddValue(new Value(ValueType::INT32, UValue(data))));
}

void OpPushInt32::Parse(ifstream& device)
{
	data = ByteArrayRead::ReadInt(device);
}
