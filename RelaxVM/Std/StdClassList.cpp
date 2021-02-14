#include "StdClassList.h"

StdClassList::StdClassList()
{
	/* Console */
	this->operator[]("Relax.Console") = (new StdClass("Relax.Console", {

		/* Write */
		StdMethod("Write", "void", "Relax.Console", QVector<Parameter>{Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			return RelaxConsole::Write(dynamic_cast<RelaxString*>(stack.pop()));
		},AccessModifier::PUBLIC, true),

		StdMethod("Write", "void", "Relax.Console", QVector<Parameter>{Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			return RelaxConsole::Write(dynamic_cast<RelaxInt32*>(stack.pop()));
		},AccessModifier::PUBLIC, true),
		
		StdMethod("Write", "void", "Relax.Console", QVector<Parameter>{Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			return RelaxConsole::Write(dynamic_cast<RelaxFloat*>(stack.pop()));
		},AccessModifier::PUBLIC, true),

		StdMethod("Write", "void", "Relax.Console", QVector<Parameter>{Parameter("Relax.Bool")}, [&](Stack& stack) -> Object*
		{
			return RelaxConsole::Write(dynamic_cast<RelaxBool*>(stack.pop()));
		},AccessModifier::PUBLIC, true),

		/* Read */
		StdMethod("Read", "Relax.String", "Relax.Console", {}, [&](Stack& stack) -> Object*
		{
			return RelaxConsole::Read();
		},AccessModifier::PUBLIC, true)
	}));

	/* String */
	this->operator[]("Relax.String") = (new StdClass("Relax.String", {

		/* Concat */
		StdMethod("Concat", "Relax.String", "Relax.String", QVector<Parameter>{Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			RelaxString* thisObject = dynamic_cast<RelaxString*>(stack.pop());
			return thisObject->Concat(dynamic_cast<RelaxString*>(stack.pop()));
		},AccessModifier::PUBLIC, false),

		/* operator+ */
		StdMethod("operator+", "Relax.String", "Relax.String", QVector<Parameter>{Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			RelaxString* thisObject = dynamic_cast<RelaxString*>(stack.pop());
			return *thisObject + dynamic_cast<RelaxString*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		/* operator== */
		StdMethod("operator==", "Relax.Bool", "Relax.String", QVector<Parameter>{Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			RelaxString* thisObject = dynamic_cast<RelaxString*>(stack.pop());
			return *thisObject == dynamic_cast<RelaxString*>(stack.pop());
		},AccessModifier::PUBLIC, false)
		
	}));

	/* Array */
	this->operator[]("Relax.Array") = (new StdClass("Relax.Array", {}));

	/* Int32 */
	this->operator[]("Relax.Int32") = (new StdClass("Relax.Int32", {
		/* operator== */
		StdMethod("operator==", "Relax.Bool", "Relax.Int32", QVector<Parameter>{Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			return *thisObject == dynamic_cast<RelaxInt32*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		/* operator+ */
		StdMethod("operator+", "Relax.Int32", "Relax.Int32", QVector<Parameter>{Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			return *thisObject + dynamic_cast<RelaxInt32*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		
		/* operator- */
		StdMethod("operator-", "Relax.Int32", "Relax.Int32", QVector<Parameter>{Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			return *thisObject - dynamic_cast<RelaxInt32*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		/* operator* */
		StdMethod("operator*", "Relax.Int32", "Relax.Int32", QVector<Parameter>{Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			return *thisObject * dynamic_cast<RelaxInt32*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		
		/* operator/ */
		StdMethod("operator/", "Relax.Int32", "Relax.Int32", QVector<Parameter>{Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			return *thisObject / dynamic_cast<RelaxInt32*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		/* cast */
		StdMethod("cast", "Relax.Int32", "Relax.Int32", QVector<Parameter>{Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* data = dynamic_cast<RelaxFloat*>(stack.pop());
			return RelaxInt32::cast(data);
		},AccessModifier::PUBLIC, true),
	}));

	/* Float */
	this->operator[]("Relax.Float") = (new StdClass("Relax.Float", {
		
		/* operator== */
		StdMethod("operator==", "Relax.Bool", "Relax.Float", QVector<Parameter>{Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			return *thisObject == dynamic_cast<RelaxFloat*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		/* operator+ */
		StdMethod("operator+", "Relax.Float", "Relax.Float", QVector<Parameter>{Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			return *thisObject + dynamic_cast<RelaxFloat*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		/* operator- */
		StdMethod("operator-", "Relax.Float", "Relax.Float", QVector<Parameter>{Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			return *thisObject - dynamic_cast<RelaxFloat*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		/* operator* */
		StdMethod("operator*", "Relax.Float", "Relax.Float", QVector<Parameter>{Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			return *thisObject * dynamic_cast<RelaxFloat*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		/* operator/ */
		StdMethod("operator/", "Relax.Float", "Relax.Float", QVector<Parameter>{Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			return *thisObject / dynamic_cast<RelaxFloat*>(stack.pop());
		},AccessModifier::PUBLIC, false),

		/* cast */
		StdMethod("cast", "Relax.Float", "Relax.Float", QVector<Parameter>{Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* data = dynamic_cast<RelaxInt32*>(stack.pop());
			return RelaxFloat::cast(data);
		},AccessModifier::PUBLIC, true),
	}));

	/* Random */
	this->operator[]("Relax.Random") = (new StdClass("Relax.Random", {
		/* GererateInt32 */
		StdMethod("GenerateInt32", "Relax.Int32", "Relax.Random", {}, [&](Stack& stack) -> Object*
		{
			return RelaxRandom::GenerateInt32();
		},AccessModifier::PUBLIC, true),

		StdMethod("GenerateInt32", "Relax.Int32", "Relax.Random", QVector<Parameter>{Parameter("Relax.Int32"), Parameter("Relax.Int32")}, [&](Stack& stack)->Object*
		{
			RelaxInt32* min = dynamic_cast<RelaxInt32*>(stack.pop());
			RelaxInt32* max = dynamic_cast<RelaxInt32*>(stack.pop());
			return RelaxRandom::GenerateInt32(min->GetData(), max->GetData());
		},AccessModifier::PUBLIC, true)
	}));

	/* Converter */
	this->operator[]("Relax.Converter") = (new StdClass("Relax.Converter", {
		/* Int32ToString */
		StdMethod("Int32ToString", "Relax.String", "Relax.Converter", QVector<Parameter>{Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			return RelaxConverter::Int32ToString(dynamic_cast<RelaxInt32*>(stack.pop()));
		},AccessModifier::PUBLIC, true),

		/* StringToInt32 */
		StdMethod("StringToInt32", "Relax.Int32", "Relax.Converter", QVector<Parameter>{Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			return RelaxConverter::StringToInt32(dynamic_cast<RelaxString*>(stack.pop()));
		},AccessModifier::PUBLIC, true)
	}));
}






StdClassList* StdClassList::GetInstance()
{
	if (stdClassList == nullptr) stdClassList = new StdClassList;
	return stdClassList;
}
