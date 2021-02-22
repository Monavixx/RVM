#include "OpRef.h"
#include "../Std/DataTypes/RelaxPointer.h"

void OpRef::Run()
{
	Object* data = frame->GetStack().pop();

	RelaxPointer* pointer = new RelaxPointer(data->GetAddress(), dataType);
	frame->GetStack().push(GlobalVariables::heap.push_back(pointer));
}

void OpRef::Parse(QIODevice& device)
{
	dataType = ByteArrayRead::ReadSizeAndString(device);
}
