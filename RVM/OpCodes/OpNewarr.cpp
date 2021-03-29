#include "OpNewarr.h"
#include "../Core/FieldObject.h"

void OpNewarr::Run()
{
	int arraySize = get<int>(frame->GetStack().pop()->value);
	RelaxArray* newArray = new RelaxArray(dataType, arraySize);
	GlobalVariables::heap.push_back(newArray);
	frame->GetStack().push(new Value(ValueType::OBJECT, UValue(newArray)));
}

void OpNewarr::Parse(ifstream& device)
{
	dataType = ByteArrayRead::ReadSizeAndString(device);
}
