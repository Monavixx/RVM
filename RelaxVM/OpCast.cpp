#include "OpCast.h"

void OpCast::Run()
{
	Object* data = frame->GetStack().top();
	
	if (isStd)
	{
		StdClass* declClass = StdClassList::GetInstance()->FindClassByName(dataType);
		if (declClass == nullptr)
			Exit("cast: decl class not found");
		StdMethod* cast = declClass->GetMethod("cast", { Parameter(data->GetDataType()) });
		if (cast == nullptr)
			Exit("cast: cast not found");

		Object* returnedObject = cast->CallFunction(frame->GetStack());
		if (returnedObject != nullptr)
		{
			gv->heap.push_back(returnedObject);
			frame->GetStack().push(returnedObject);
		}
	}
	else
	{
		Class* declClass = gv->classes.FindClassByName(dataType);
		if (declClass == nullptr)
			Exit("cast: decl class not found");
		Method* cast = declClass->GetMethod("cast", { Parameter(data->GetDataType()) });
		if (cast == nullptr)
			Exit("cast: cast not found");


		Frame* newFrame = new Frame(cast);
		newFrame->GetStack().SetMaxSize(30);

		// parameters 
		for (auto& item : cast->GetParameters())
		{
			Object* data = frame->GetStack().pop();
			if (data->GetDataType() != item.GetDataType())
				Exit("Error parameters type");
			newFrame->GetStack().push(data);
		}

		gv->frameStack.push(newFrame);
		ExecuteMethod(gv);
	}
}

void OpCast::Parse(QIODevice& device)
{
	isStd = ByteArrayRead::ReadByte(device);
	dataType = ByteArrayRead::ReadSizeAndString(device);
}
