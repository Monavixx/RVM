#include "RelaxConsole.h"
#include "../../Core/FieldObject.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"
#include "../../Core/Value.h"

void RelaxConsole::GenerateMetaInfo()
{
	metaClass = new Class("Relax.Console", true, {
		// Write
		new StdMethod("Write", "void", "Relax.Console", {Parameter("Relax.String")}, [&](Stack& stack) -> Value*
		{
			std::cout << get<String>(stack.pop()->value);
			return new Value(ValueType::_VOID);
		},AccessModifier::PUBLIC, true),

		new StdMethod("Write", "void", "Relax.Console", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Value*
		{
			std::cout << get<int>(stack.pop()->value);
			return new Value(ValueType::_VOID);
		},AccessModifier::PUBLIC, true),

		new StdMethod("Write", "void", "Relax.Console", {Parameter("Relax.Float")}, [&](Stack& stack) -> Value*
		{
			std::cout << get<float>(stack.pop()->value);
			return new Value(ValueType::_VOID);
		},AccessModifier::PUBLIC, true),

		new StdMethod("Write", "void", "Relax.Console", {Parameter("Relax.Bool")}, [&](Stack& stack) -> Value*
		{
			std::cout << get<bool>(stack.pop()->value) ? "true" : "false";
			return new Value(ValueType::_VOID);
		},AccessModifier::PUBLIC, true),

		// Read
		new StdMethod("Read", "Relax.String", "Relax.Console", {}, [&](Stack& stack) -> Value*
		{
			return new Value(ValueType::STR,  UValue(qin.readLine()));
		},AccessModifier::PUBLIC, true)
	});

	if (Args::contains("-p2w"))
	{
		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.String")}, [&](Stack& stack) -> Value*
			{
				std::cout << get<String>(stack.pop()->value);
				return new Value(ValueType::_VOID);
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Value*
			{
				std::cout << get<int>(stack.pop()->value);
				return new Value(ValueType::_VOID);
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Float")}, [&](Stack& stack) -> Value*
			{
				std::cout << get<float>(stack.pop()->value);
				return new Value(ValueType::_VOID);
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Bool")}, [&](Stack& stack) -> Value*
			{
				std::cout << get<bool>(stack.pop()->value) ? "true" : "false";
				return new Value(ValueType::_VOID);
			}, AccessModifier::PUBLIC, true));
	}
	else
	{
		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.String")}, [&](Stack& stack) -> Value*
			{
				qout << get<String>(stack.pop()->value);
				return new Value(ValueType::_VOID);
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Value*
			{
				qout << std::to_string(get<int>(stack.pop()->value));
				return new Value(ValueType::_VOID);
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Float")}, [&](Stack& stack) -> Value*
			{
				qout << std::to_string(get<float>(stack.pop()->value));
				return new Value(ValueType::_VOID);
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Bool")}, [&](Stack& stack) -> Value*
			{
				qout << (get<bool>(stack.pop()->value) ? "true" : "false");
				return new Value(ValueType::_VOID);
			}, AccessModifier::PUBLIC, true));
	}
}
