#include "ExecuteMethod.h"
#include "../Libs/ConsoleTextStream.h"

void ExecuteMethod(bool gc)
{
	Frame* frame = GlobalVariables::frameStack.top();
	Method* method = frame->GetMethod();
	if (method == nullptr)
	{
		Exit("main method not found");
	}

	int i = 0;
	while (!frame->IsEnd())
	{
		OpBase* op = frame->Next();
		op->SetFrame(frame);

		op->Run();
		if (dynamic_cast<OpReturn*>(op) != nullptr) return;
	}
}
