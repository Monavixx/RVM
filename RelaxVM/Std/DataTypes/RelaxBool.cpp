#include "RelaxBool.h"
#include "../../Core/Class.h"

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
	metaClass = new Class("Relax.Bool");
}
