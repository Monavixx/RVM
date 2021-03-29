#include "OpEqual.h"
#include "../Core/FieldObject.h"

void OpEqual::Run()
{
	Value* firstData = frame->GetStack().pop();
	Value* secondData = frame->GetStack().pop();

	switch (firstData->valueType)
	{
	case ValueType::INT32:
		frame->GetStack().push(frame->AddValue(new Value(ValueType::BOOL, UValue{ .boolean = firstData->value.inum == secondData->value.inum })));
		break;

	case ValueType::FLOAT:
		frame->GetStack().push(frame->AddValue(new Value(ValueType::BOOL, UValue{ .boolean = firstData->value.fnum == secondData->value.fnum })));
		break;

	default:
		Exit("equal: data type is not a number");
	}
}

void OpEqual::Parse(ifstream& device)
{
}
