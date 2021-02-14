#include "RelaxConverter.h"

QString RelaxConverter::GetDataType()
{
    return "Relax.Converter";
}

RelaxInt32* RelaxConverter::StringToInt32(RelaxString* data)
{
    bool isOk;
    int num = data->GetData().toInt(&isOk);
    if (!isOk)
        Exit("StringToInt32: error convertation");
    return new RelaxInt32(num);
}

RelaxString* RelaxConverter::Int32ToString(RelaxInt32* data)
{
    return new RelaxString(QString::number(data->GetData()));
}
