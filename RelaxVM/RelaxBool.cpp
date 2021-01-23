#include "RelaxBool.h"

RelaxBool::RelaxBool(bool data) : data(data)
{
}

QString RelaxBool::GetDataType()
{
	return "Relax.Bool";
}

bool RelaxBool::GetData()
{
	return data;
}

void RelaxBool::SetData(bool data)
{
	this->data = data;
}
