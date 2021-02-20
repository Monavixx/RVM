#include "OpGc.h"

void OpGc::Run()
{
	/*for (auto& item : GlobalVariables::heap)
	{
		if (item != nullptr)
		{
			if (item->GetAmountUsers() <= 0)
			{
				delete item;
				item = nullptr;
			}
		}
	}
	GlobalVariables::heap.removeAll(nullptr);*/
	for (int i = 0; i < GlobalVariables::heap.size(); ++i)
	{
		if (GlobalVariables::heap[i] == nullptr)
		{
			GlobalVariables::heap.removeAt(i);
		}
		else if (GlobalVariables::heap[i]->GetAmountUsers() <= 0)
		{
			delete GlobalVariables::heap[i];
			GlobalVariables::heap.removeAt(i);
		}
	}
}

void OpGc::Parse(QIODevice& device)
{
}
