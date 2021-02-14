#include "OpCast.h"

void OpCast::Run()
{
	Object* data = frame->GetStack().top();
	
	if (isStd)
	{
		StdClass* declClass = (*StdClassList::GetInstance())[dataType];
		if (declClass == nullptr)
			Exit("cast: decl class not found");
		StdMethod* cast = declClass->GetMethod("cast", { Parameter(data->GetDataType()) });
		if (cast == nullptr)
			Exit("cast: cast not found");

		cast->CallFunction(gv, frame);
	}
	else
	{
		Class* declClass = gv->classes.FindClassByName(dataType);
		if (declClass == nullptr)
			Exit("cast: decl class not found");
		Method* cast = declClass->GetMethod("cast", { Parameter(data->GetDataType()) });
		if (cast == nullptr)
			Exit("cast: cast not found");


		cast->CallMethod(gv, frame);
	}
}

void OpCast::Parse(QIODevice& device)
{
	isStd = ByteArrayRead::ReadByte(device);
	dataType = ByteArrayRead::ReadSizeAndString(device);
}
