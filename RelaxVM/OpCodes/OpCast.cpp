#include "OpCast.h"

void OpCast::Run()
{
	Object* data = frame->GetStack().top();
	
	if (isStd)
	{
		StdMethod* stdMethodCast = declStdClass->GetMethod("cast", { Parameter(data->GetDataType()) });
		if (stdMethodCast == nullptr)
			Exit("cast: cast not found");

		stdMethodCast->CallFunction(frame);
	}
	else
	{
		Method* methodCast = declClass->GetMethod("cast", { Parameter(data->GetDataType()) });
		if (methodCast == nullptr)
			Exit("cast: cast not found");


		methodCast->CallMethod(frame);
	}
}

void OpCast::Parse(QIODevice& device)
{
	isStd = ByteArrayRead::ReadByte(device);
	dataType = ByteArrayRead::ReadSizeAndString(device);

	if (isStd)
	{
		declStdClass = (*StdClassList::GetInstance())[dataType];
		if (declStdClass == nullptr)
			Exit("cast: decl class not found");
	}
	else
	{
		declClass = GlobalVariables::classes.FindClassByName(dataType);
		if (declClass == nullptr)
			Exit("cast: decl class not found");
	}
}
