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

void RelaxConverter::GenerateMetaInfo()
{
    metaClass = new StdClass("Relax.Converter", {
		// Int32ToString
		StdMethod("Int32ToString", "Relax.String", "Relax.Converter", QVector<Parameter>{Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			return RelaxConverter::Int32ToString(dynamic_cast<RelaxInt32*>(stack.pop()));
		},AccessModifier::PUBLIC, true),

		// StringToInt32
		StdMethod("StringToInt32", "Relax.Int32", "Relax.Converter", QVector<Parameter>{Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			return RelaxConverter::StringToInt32(dynamic_cast<RelaxString*>(stack.pop()));
		},AccessModifier::PUBLIC, true)
	});
}
