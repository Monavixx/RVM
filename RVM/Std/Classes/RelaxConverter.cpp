#include "RelaxConverter.h"
#include "../../Core/FieldObject.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"
#include "../../Core/FieldObject.h"

int RelaxConverter::StringToInt32(const String& data)
{
    bool isOk;
    int num = toInt(data, &isOk);
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
			return new Value(ValueType::STR, UValue(String(to_string(get<int>(stack.pop()->value)))));
		},AccessModifier::PUBLIC, true),

		// StringToInt32
		new StdMethod("StringToInt32", "Relax.Int32", "Relax.Converter", {Parameter("Relax.String")}, [&](Stack& stack) -> Value*
		{
			return new Value(ValueType::INT32, UValue(StringToInt32(get<String>(stack.pop()->value))));
		},AccessModifier::PUBLIC, true)
	});
}
