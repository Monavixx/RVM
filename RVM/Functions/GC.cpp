#include "GC.h"
#include "../Core/FieldObject.h"

void GC()
{
	for (size_t i = 0; i < GlobalVariables::heap.GetSize(); ++i)
	{
		if (GlobalVariables::heap[i] != nullptr)
		if (GlobalVariables::heap[i]->GetAmountUsers() <= 0)
		{
			GlobalVariables::heap.Delete(i);
		}
	}
}
