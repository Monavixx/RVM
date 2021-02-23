#include "OpGc.h"

void OpGc::Run()
{
	for (int i = 0; i < GlobalVariables::heap.GetSize(); ++i)
	{
		if(GlobalVariables::heap[i] != nullptr)
		if (GlobalVariables::heap[i]->GetAmountUsers() <= 0)
		{
			GlobalVariables::heap.Delete(i);
		}
	}
}

void OpGc::Parse(QIODevice& device)
{
}
