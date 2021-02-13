#include "OpNew.h"

void OpNew::Run()
{
	Object* object = nullptr;
	if (isStd)
	{
		StdClass* _class = StdClassList::GetInstance()->FindClassByName(className);
		if (_class == nullptr)
			Exit("new: Std class not exists");

		StdMethod* construction = _class->GetMethod(className, parameters);
		if (construction == nullptr)
			Exit("new: Construction not exists");

		construction->CallFunction(gv, frame);
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
