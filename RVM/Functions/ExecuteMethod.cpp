#include "ExecuteMethod.h"
#include "../Libs/ConsoleTextStream.h"
#include "../Core/Method.h"
#include "GC.h"
#include "../Core/FieldObject.h"

void ExecuteMethod(bool gc)
{
	Frame* frame = GlobalVariables::frameStack.top();
	Method* method = dynamic_cast<Method*>(frame->GetMethod());
	if (method == nullptr)
	{
		Exit("main method not found");
	}

	static size_t i = 0;
	bool isReturn = false;
	while (!frame->IsEnd())
	{
		OpBase* op = frame->Next();
		op->SetFrame(frame);

		op->Run();
		if (dynamic_cast<OpReturn*>(op) != nullptr)
		{
			isReturn = true;
			delete frame;
			return;
		}

		if (i >= GlobalVariables::opCodesForGC)
		{
			GC();
			i = 0;
		}
		++i;
	}
	if (!isReturn)
	{
		delete frame;
		GlobalVariables::frameStack.pop();
	}

}
