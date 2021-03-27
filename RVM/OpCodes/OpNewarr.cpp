#include "OpNewarr.h"
#include "../Core/FieldObject.h"

void OpNewarr::Run()
{
	int arraySize = frame->GetStack().pop()->value.inum;
	RelaxArray* newArray = new RelaxArray(dataType, arraySize);
	GlobalVariables::heap.push_back(newArray);
	frame->GetStack().push(new Value(ValueType::OBJECT, UValue{ .object = newArray }));
}

void OpNewarr::Parse(HANDLE& device)
{
	dataType = ByteArrayRead::ReadSizeAndString(device);
}
