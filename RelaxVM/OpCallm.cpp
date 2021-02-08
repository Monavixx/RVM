#include "OpCallm.h"

void OpCallm::Run()
{
	if (isStd)
	{
		StdClass* stdClass = StdClassList::GetInstance()->FindClassByName(declClassName);
		if (stdClass == nullptr)
			Exit("std class not exists");

		StdMethod* callableStdMethod = stdClass->GetMethod(name, parameters);
		if (callableStdMethod == nullptr)
			Exit("std method not exists");

		Object* returnedObject = callableStdMethod->CallFunction(frame->GetStack());
		if (returnedObject != nullptr)
		{
			gv->heap.push_back(returnedObject);
			frame->GetStack().push(returnedObject);
		}
	}
	else
	{
		Class* declClass = gv->classes.FindClassByName(declClassName);
		if (declClass == nullptr)
			Exit("Callm: class not found");

		Method* callableMethod = declClass->GetMethod(name, parameters);
		if (callableMethod == nullptr)
			Exit("Callm: method not found");

		Frame* frame = new Frame(callableMethod);
		frame->GetStack().SetMaxSize(30);

		// parameters 
		for (auto& item : callableMethod->GetParameters())
		{
			Object* data = frame->GetStack().pop();
			if (data->GetDataType() != item.GetDataType())
				Exit("Error parameters type");
			frame->GetStack().push(data);
		}


		gv->frameStack.push(frame);
		ExecuteMethod();
	}
}

void OpCallm::Parse(QIODevice& device)
{
	isStd = ByteArrayRead::ReadByte(device);
	isStatic = ByteArrayRead::ReadByte(device);
	declClassName = ByteArrayRead::ReadSizeAndString(device);
	name = ByteArrayRead::ReadSizeAndString(device);
	int amountParameters = ByteArrayRead::ReadInt(device);

	for (int i = 0; i < amountParameters; ++i)
	{
		QString parameterDataType = ByteArrayRead::ReadSizeAndString(device);
		Parameter parameter(parameterDataType);
		parameters.push_back(parameter);
	}
}

void OpCallm::ExecuteMethod()
{
	Frame* newFrame = gv->frameStack.top();
	Method* method = newFrame->GetMethod();

	if (method == nullptr)
	{
		Exit("main method not found");
	}

	while (!newFrame->IsEnd())
	{
		OpBase* op = newFrame->Next();
		op->SetFrame(newFrame);
		op->Run();
		if (dynamic_cast<OpReturn*>(op) != nullptr) return;
	}
}