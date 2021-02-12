#include "StdClassList.h"

StdClassList::StdClassList()
{
	/* Console */
	push_back(StdClass("Relax.Console", {

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
	push_back(StdClass("Relax.String", {}));

	/* Array */
	push_back(StdClass("Relax.Array", {}));

	/* Int32 */
	push_back(StdClass("Relax.Int32", {
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
	push_back(StdClass("Relax.Float", {
		
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
	push_back(StdClass("Relax.Random", {
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
}








StdClass* StdClassList::FindClassByName(const QString& name)
{
	auto classIterator = std::find_if(this->begin(), this->end(), [&](const StdClass& stdClass) {
		return stdClass.GetName() == name;
	});

	if (classIterator == this->end())
		return nullptr;
	return &(*classIterator);
}

StdClassList* StdClassList::GetInstance()
{
	if (stdClassList == nullptr) stdClassList = new StdClassList;
	return stdClassList;
}
