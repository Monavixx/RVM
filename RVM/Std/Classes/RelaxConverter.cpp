#include "RelaxConverter.h"
#include "../../Core/FieldObject.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"
#include "../../Core/FieldObject.h"

int RelaxConverter::StringToInt32(const String& data)
{
    bool isOk;
    int num = data.toInt(&isOk);
    if (!isOk)
        Exit("StringToInt32: error convertation");
    return num;
}


void RelaxConverter::GenerateMetaInfo()
{
    metaClass = new Class("Relax.Converter", true, {
		// Int32ToString
		new StdMethod("Int32ToString", "Relax.String", "Relax.Converter", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Value*
		{
			return new Value(ValueType::STR, UValue{.str = String(stack.pop()->value.inum)});
		},AccessModifier::PUBLIC, true),

		// StringToInt32
		new StdMethod("StringToInt32", "Relax.Int32", "Relax.Converter", {Parameter("Relax.String")}, [&](Stack& stack) -> Value*
		{
			return new Value(ValueType::INT32, UValue{.inum = StringToInt32(stack.pop()->value.str)});
		},AccessModifier::PUBLIC, true)
	});
}
