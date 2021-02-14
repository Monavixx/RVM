#include "RelaxConverter.h"

QString RelaxConverter::GetDataType()
{
    return "Relax.Converter";
}

RelaxInt32* RelaxConverter::StringToInt32(RelaxString* data)
{
    return new RelaxInt32(data->GetData().toInt());
}

RelaxString* RelaxConverter::Int32ToString(RelaxInt32* data)
{
    return new RelaxString(QString::number(data->GetData()));
}
