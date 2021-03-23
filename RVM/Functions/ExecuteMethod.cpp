#include "ExecuteMethod.h"
#include "../Libs/ConsoleTextStream.h"
#include "../Core/Method.h"
#include "GC.h"

void ExecuteMethod(bool gc)
{
	Frame* frame = GlobalVariables::frameStack.top();
	Method* method = dynamic_cast<Method*>(frame->GetMethod());
	if (method == nullptr)
	{
		Exit("main method not found");
	}

	size_t i = 0;
	while (!frame->IsEnd())
	{
		OpBase* op = frame->Next();
		op->SetFrame(frame);

		op->Run();
		if (dynamic_cast<OpReturn*>(op) != nullptr) return;

		/*if (i >= GlobalVariables::opCodesForGC)
			GC();
		++i;*/
	}
}
