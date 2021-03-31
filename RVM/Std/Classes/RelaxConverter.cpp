#include "RelaxConverter.h"
#include "../../Core/FieldObject.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"
#include "../../Core/FieldObject.h"

int RelaxConverter::ToInt32(const String& data)
{
    bool isOk;
    int num = toInt(data, &isOk);
    if (!isOk)
        Exit("Relax.Converter.ToInt32: conversion error");
    return num;
}

float RelaxConverter::ToFloat(const String& data)
{
	float res;
	vector<String> splitData = split(data, '.');
	if (splitData.size() != 2) Exit("Relax.Converter.ToFloat: conversion error");
	bool errNum, errFrac;
	int num = toInt(splitData[0], &errNum), fracPart = toInt(splitData[1], &errFrac);
	if (!(errNum && errFrac)) Exit("Relax.Converter.ToFloat: conversion error");

	short numberOfDigitsInFractionalPart = (fracPart == 0 ? 1 : short(log10(fracPart) + 1));
	res = num + float(fracPart) / float(pow(10, numberOfDigitsInFractionalPart));
	return res;
}


void RelaxConverter::GenerateMetaInfo()
{
    metaClass = new Class("Relax.Converter", true, {
		// ToString
		new StdMethod("ToString", "Relax.String", "Relax.Converter", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Value*
		{
			return new Value(ValueType::STR, UValue(String(to_string(get<int>(stack.pop()->value)))));
		},AccessModifier::PUBLIC, true),

		new StdMethod("ToString", "Relax.String", "Relax.Converter", {Parameter("Relax.Float")}, [&](Stack& stack) -> Value*
		{
			return new Value(ValueType::STR, UValue(String(to_string(get<float>(stack.pop()->value)))));
		},AccessModifier::PUBLIC, true),

		new StdMethod("ToString", "Relax.String", "Relax.Converter", {Parameter("Relax.Bool")}, [&](Stack& stack) -> Value*
		{
			return new Value(ValueType::STR, UValue(String(get<bool>(stack.pop()->value) == true ? "true" : "false")));
		},AccessModifier::PUBLIC, true),

		// ToInt32
		new StdMethod("ToInt32", "Relax.Int32", "Relax.Converter", {Parameter("Relax.String")}, [&](Stack& stack) -> Value*
		{
			return new Value(ValueType::INT32, UValue(ToInt32(get<String>(stack.pop()->value))));
		},AccessModifier::PUBLIC, true),

		// ToBool
		new StdMethod("ToBool", "Relax.Bool", "Relax.Converter", {Parameter("Relax.String")}, [&](Stack& stack) -> Value*
		{
			String str = get<String>(stack.pop()->value);
			if (str == "true") return new Value(ValueType::BOOL, UValue(true));
			else if (str == "false") return new Value(ValueType::BOOL, UValue(false));
			else Exit("Relax.Converter.ToBool: conversion error");
		},AccessModifier::PUBLIC, true),

		// ToFloat
		new StdMethod("ToFloat", "Relax.Float", "Relax.Converter", {Parameter("Relax.String")}, [&](Stack& stack) -> Value*
		{
			String str = get<String>(stack.pop()->value);
			return new Value(ValueType::FLOAT, UValue(ToFloat(str)));
		},AccessModifier::PUBLIC, true),
	});
}
