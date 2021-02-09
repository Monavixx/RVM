#include "OpGc.h"

void OpGc::Run()
{
	for (auto& item : gv->heap)
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
	gv->heap.removeAll(nullptr);
}

void OpGc::Parse(QIODevice& device)
{
}
