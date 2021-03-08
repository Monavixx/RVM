#include "RelaxBool.h"
#include "../StdClass.h"

RelaxBool::RelaxBool(bool data) : data(data)
{
}

bool RelaxBool::GetData()
{
	return data;
}

void RelaxBool::SetData(bool data)
{
	this->data = data;
}

void RelaxBool::GenerateMetaInfo()
{
	metaClass = new StdClass("Relax.Bool");
}
