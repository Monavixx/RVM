#include "OpNew.h"

void OpNew::Run()
{
	Object* object = nullptr;
	if (isStd)
	{
		StdClass* _class = StdClassList::GetInstance()->FindClassByName(className);
		if (_class == nullptr)
			Exit("Std class not exists");

		StdMethod* construction = _class->GetMethod(className, parameters);
		if (construction == nullptr)
			Exit("Construction not exists");

		Object* newObject = construction->CallFunction(frame->GetStack());
		gv->heap.push_back(newObject);
		frame->GetStack().push(newObject);
	}
}

void OpNew::Parse(QIODevice& device)
{
	isStd = ByteArrayRead::ReadByte(device);
	className = ByteArrayRead::ReadSizeAndString(device);
	int amountParameters = ByteArrayRead::ReadInt(device);

	for (int i = 0; i < amountParameters; ++i)
	{
		QString parameterDataType = ByteArrayRead::ReadSizeAndString(device);
		Parameter parameter(parameterDataType);
		parameters.push_back(parameter);
	}
}
