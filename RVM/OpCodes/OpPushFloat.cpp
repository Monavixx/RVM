#include "OpPushFloat.h"
#include "../Core/FieldObject.h"

void OpPushFloat::Run()
{
	frame->GetStack().push(frame->AddValue(new Value(ValueType::FLOAT, UValue(data))));
}

void OpPushFloat::Parse(ifstream& device)
{
	data = ByteArrayRead::ReadFloat(device);
}
