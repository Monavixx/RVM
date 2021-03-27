#include "OpPushStr.h"
#include "../Core/FieldObject.h"

void OpPushStr::Run()
{
	frame->GetStack().push(frame->AddValue(new Value(ValueType::STR,  UValue{.str = data} )));
}

void OpPushStr::Parse(HANDLE& device)
{
	data = ByteArrayRead::ReadSizeAndString(device);
}
