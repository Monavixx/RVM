#include "RelaxConsole.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"

Object* RelaxConsole::Write(RelaxString* data)
{
	std::cout << data->GetData().toStdString();
	return nullptr;
}

Object* RelaxConsole::Write(RelaxInt32* data)
{
	std::cout << data->GetData();
	return nullptr;
}

Object* RelaxConsole::Write(RelaxFloat* data)
{
	std::cout << data->GetData();
	return nullptr;
}

Object* RelaxConsole::Write(RelaxBool* data)
{
	std::cout << (data->GetData() ? "true" : "false");
	return nullptr;
}

Object* RelaxConsole::Print(RelaxString* data)
{
	qout << data->GetData();
	return nullptr;
}

Object* RelaxConsole::Print(RelaxInt32* data)
{
	qout << data->GetData();
	return nullptr;
}

Object* RelaxConsole::Print(RelaxFloat* data)
{
	qout << data->GetData();
	return nullptr;
}

Object* RelaxConsole::Print(RelaxBool* data)
{
	qout << (data->GetData() ? "true" : "false");
	return nullptr;
}

RelaxString* RelaxConsole::Read()
{
	return new RelaxString(qin.readLine());
}

void RelaxConsole::GenerateMetaInfo()
{
	metaClass = new Class("Relax.Console", true, {
		// Write
		new StdMethod("Write", "void", "Relax.Console", {Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			return RelaxConsole::Write(dynamic_cast<RelaxString*>(stack.pop()));
		},AccessModifier::PUBLIC, true),

		new StdMethod("Write", "void", "Relax.Console", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			return RelaxConsole::Write(dynamic_cast<RelaxInt32*>(stack.pop()));
		},AccessModifier::PUBLIC, true),

		new StdMethod("Write", "void", "Relax.Console", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			return RelaxConsole::Write(dynamic_cast<RelaxFloat*>(stack.pop()));
		},AccessModifier::PUBLIC, true),

		new StdMethod("Write", "void", "Relax.Console", {Parameter("Relax.Bool")}, [&](Stack& stack) -> Object*
		{
			return RelaxConsole::Write(dynamic_cast<RelaxBool*>(stack.pop()));
		},AccessModifier::PUBLIC, true),

		// Read
		new StdMethod("Read", "Relax.String", "Relax.Console", {}, [&](Stack& stack) -> Object*
		{
			return RelaxConsole::Read();
		},AccessModifier::PUBLIC, true)
	});

	if (Args::contains("-p2w"))
	{
		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.String")}, [&](Stack& stack) -> Object*
			{
				return RelaxConsole::Write(dynamic_cast<RelaxString*>(stack.pop()));
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
			{
				return RelaxConsole::Write(dynamic_cast<RelaxInt32*>(stack.pop()));
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
			{
				return RelaxConsole::Write(dynamic_cast<RelaxFloat*>(stack.pop()));
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Bool")}, [&](Stack& stack) -> Object*
			{
				return RelaxConsole::Write(dynamic_cast<RelaxBool*>(stack.pop()));
			}, AccessModifier::PUBLIC, true));
	}
	else
	{
		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.String")}, [&](Stack& stack) -> Object*
			{
				return RelaxConsole::Print(dynamic_cast<RelaxString*>(stack.pop()));
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
			{
				return RelaxConsole::Print(dynamic_cast<RelaxInt32*>(stack.pop()));
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
			{
				return RelaxConsole::Print(dynamic_cast<RelaxFloat*>(stack.pop()));
			}, AccessModifier::PUBLIC, true));

		metaClass->AddMethod(new StdMethod("Print", "void", "Relax.Console", {Parameter("Relax.Bool")}, [&](Stack& stack) -> Object*
			{
				return RelaxConsole::Print(dynamic_cast<RelaxBool*>(stack.pop()));
			}, AccessModifier::PUBLIC, true));
	}
}
