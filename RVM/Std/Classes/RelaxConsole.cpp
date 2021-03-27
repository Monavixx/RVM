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
			std::cout << stack.pop()->value.str.toStdString();
			return new Value(ValueType::_VOID);
		},AccessModifier::PUBLIC, true),

		new StdMethod("Write", "void", "Relax.Console", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Value*
		{
			std::cout << stack.pop()->value.inum;
			return new Value(ValueType::_VOID);
		},AccessModifier::PUBLIC, true),

		new StdMethod("Write", "void", "Relax.Console", {Parameter("Relax.Float")}, [&](Stack& stack) -> Value*
		{
			std::cout << stack.pop()->value.fnum;
			return new Value(ValueType::_VOID);
		},AccessModifier::PUBLIC, true),

		new StdMethod("Write", "void", "Relax.Console", {Parameter("Relax.Bool")}, [&](Stack& stack) -> Value*
		{
			std::cout << stack.pop()->value.boolean ? "true" : "false";
			return new Value(ValueType::_VOID);
		},AccessModifier::PUBLIC, true),

		// Read
		new StdMethod("Read", "Relax.String", "Relax.Console", {}, [&](Stack& stack) -> Value*
		{
			return new Value(ValueType::STR,  UValue{.str = qin.readLine()});
		},AccessModifier::PUBLIC, true)
	});

	if (Args::contains("-p2w"))
	{
		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.String")}, [&](Stack& stack) -> Value*
			{
				std::cout << stack.pop()->value.str.toStdString();
				return new Value(ValueType::_VOID);
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Value*
			{
				std::cout << stack.pop()->value.inum;
				return new Value(ValueType::_VOID);
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Float")}, [&](Stack& stack) -> Value*
			{
				std::cout << stack.pop()->value.fnum;
				return new Value(ValueType::_VOID);
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Bool")}, [&](Stack& stack) -> Value*
			{
				std::cout << stack.pop()->value.boolean ? "true" : "false";
				return new Value(ValueType::_VOID);
			}, AccessModifier::PUBLIC, true));
	}
	else
	{
		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.String")}, [&](Stack& stack) -> Value*
			{
				qout << stack.pop()->value.str;
				return new Value(ValueType::_VOID);
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Value*
			{
				qout << stack.pop()->value.inum;
				return new Value(ValueType::_VOID);
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Float")}, [&](Stack& stack) -> Value*
			{
				qout << std::to_string(stack.pop()->value.fnum);
				return new Value(ValueType::_VOID);
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Bool")}, [&](Stack& stack) -> Value*
			{
				qout << (stack.pop()->value.boolean ? "true" : "false");
				return new Value(ValueType::_VOID);
			}, AccessModifier::PUBLIC, true));
	}
}
