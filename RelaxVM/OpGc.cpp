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
	std::erase(gv->heap, nullptr);
}

void OpGc::Parse(QIODevice& device)
{
}
