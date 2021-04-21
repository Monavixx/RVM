#include "ExecuteMethod.h"
#include "../Libs/ConsoleTextStream.h"
#include "../Core/Method.h"
#include "GC.h"
#include "../Core/FieldObject.h"

void ExecuteMethod()
{
	Frame* frame = GlobalVariables::frameStack.top();
	Method* method = dynamic_cast<Method*>(frame->GetMethod());
	if (method == nullptr)
	{
		Exit("execute method method not found", 1);
	}

	while (!frame->IsEnd())
	{
		OpBase* op = frame->Next();
		op->SetFrame(frame);

		op->Run();
		if (dynamic_cast<OpReturn*>(op) != nullptr)
		{
			return;
		}
	}

}
