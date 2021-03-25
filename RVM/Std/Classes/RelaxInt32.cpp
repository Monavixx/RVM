#include "RelaxInt32.h"
#include "RelaxFloat.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"

RelaxInt32::RelaxInt32(int data) : data(data)
{
}

void RelaxInt32::GenerateMetaInfo()
{
    metaClass = new Class("Relax.Int32", true, {
		// operator==
		new StdMethod("operator==", "Relax.Bool", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			return new RelaxBool(dynamic_cast<RelaxInt32*>(stack.pop())->GetData() == dynamic_cast<RelaxInt32*>(stack.pop())->GetData());
		},AccessModifier::PUBLIC, false),

		new StdMethod("operator!=", "Relax.Bool", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			return new RelaxBool(dynamic_cast<RelaxInt32*>(stack.pop())->GetData() != dynamic_cast<RelaxInt32*>(stack.pop())->GetData());
		},AccessModifier::PUBLIC, false),

		new StdMethod("operator>", "Relax.Bool", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			return new RelaxBool(dynamic_cast<RelaxInt32*>(stack.pop())->GetData() > dynamic_cast<RelaxInt32*>(stack.pop())->GetData());
		},AccessModifier::PUBLIC, false),

		new StdMethod("operator<", "Relax.Bool", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			return new RelaxBool(dynamic_cast<RelaxInt32*>(stack.pop())->GetData() < dynamic_cast<RelaxInt32*>(stack.pop())->GetData());
		},AccessModifier::PUBLIC, false),

		new StdMethod("operator>=", "Relax.Bool", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			return new RelaxBool(dynamic_cast<RelaxInt32*>(stack.pop())->GetData() >= dynamic_cast<RelaxInt32*>(stack.pop())->GetData());
		},AccessModifier::PUBLIC, false),

		new StdMethod("operator<=", "Relax.Bool", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			return new RelaxBool(dynamic_cast<RelaxInt32*>(stack.pop())->GetData() <= dynamic_cast<RelaxInt32*>(stack.pop())->GetData());
		},AccessModifier::PUBLIC, false),

		// operator+
		new StdMethod("operator+", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			return new RelaxInt32(dynamic_cast<RelaxInt32*>(stack.pop())->GetData() + dynamic_cast<RelaxInt32*>(stack.pop())->GetData());
		},AccessModifier::PUBLIC, false),

		// operator-
		new StdMethod("operator-", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			return new RelaxInt32(dynamic_cast<RelaxInt32*>(stack.pop())->GetData() - dynamic_cast<RelaxInt32*>(stack.pop())->GetData());
		},AccessModifier::PUBLIC, false),

		// operator*
		new StdMethod("operator*", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			return new RelaxInt32(dynamic_cast<RelaxInt32*>(stack.pop())->GetData() * dynamic_cast<RelaxInt32*>(stack.pop())->GetData());
		},AccessModifier::PUBLIC, false),

		// operator/
		new StdMethod("operator/", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			return new RelaxInt32(dynamic_cast<RelaxInt32*>(stack.pop())->GetData() / dynamic_cast<RelaxInt32*>(stack.pop())->GetData());
		},AccessModifier::PUBLIC, false),

		// cast
		new StdMethod("cast", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			return new RelaxInt32(dynamic_cast<RelaxFloat*>(stack.pop())->GetData());
		},AccessModifier::PUBLIC, true)
    });
}