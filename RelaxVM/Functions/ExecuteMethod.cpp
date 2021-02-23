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

		for (int i = 0; i < GlobalVariables::heap.GetSize(); ++i)
		{
			Object* data = GlobalVariables::heap[i];
			int a = 4;
		}

		op->Run();
		if (dynamic_cast<OpReturn*>(op) != nullptr) return;
		/*if (gc && i == GlobalVariables::opCodesForGC)
		{

		}*/
		for (int i = 0; i < GlobalVariables::heap.GetSize(); ++i)
		{
			Object* data = GlobalVariables::heap[i];
			int a = 4;
		}
	}
}
