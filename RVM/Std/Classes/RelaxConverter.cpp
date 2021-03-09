#include "RelaxConverter.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"

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
    return new RelaxString(data->GetData());
}

void RelaxConverter::GenerateMetaInfo()
{
    metaClass = new Class("Relax.Converter", {
		// Int32ToString
		new StdMethod("Int32ToString", "Relax.String", "Relax.Converter", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			return RelaxConverter::Int32ToString(dynamic_cast<RelaxInt32*>(stack.pop()));
		},AccessModifier::PUBLIC, true),

		// StringToInt32
		new StdMethod("StringToInt32", "Relax.Int32", "Relax.Converter", {Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			return RelaxConverter::StringToInt32(dynamic_cast<RelaxString*>(stack.pop()));
		},AccessModifier::PUBLIC, true)
	});
}
