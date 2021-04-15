#include "OpRef.h"
#include "../Core/FieldObject.h"
#include "../Std/Classes/RelaxPointer.h"

void OpRef::Run()
{
	RelaxPointer* pointer = new RelaxPointer(frame->GetStack().pop(), dataType);
	GlobalVariables::heap.push_back(pointer);
	frame->GetStack().push(frame->AddValue(new Value(ValueType::OBJECT,  UValue(pointer->GetAddress()))));
}

void OpRef::Parse(ifstream& device)
{
	dataType = ByteArrayRead::ReadSizeAndString(device);
}
