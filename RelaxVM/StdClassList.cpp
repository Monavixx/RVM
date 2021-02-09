#include "StdClassList.h"

StdClassList::StdClassList()
{
	/* Console */
	push_back(StdClass("Relax.Console", {
		StdMethod("Write", "void", "Relax.Console", {Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			if(Args::contains("-iostd"))
				std::cout << dynamic_cast<RelaxString*>(stack.pop())->GetData().toStdString();
			else
				qout << dynamic_cast<RelaxString*>(stack.pop())->GetData();
			return nullptr;
		},AccessModifier::PUBLIC, true),

		StdMethod("Write", "void", "Relax.Console", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			if (Args::contains("-iostd"))
				std::cout << dynamic_cast<RelaxInt32*>(stack.pop())->GetData();
			else
				qout << QString::number(dynamic_cast<RelaxInt32*>(stack.pop())->GetData());
			return nullptr;
		},AccessModifier::PUBLIC, true),
		
		StdMethod("Write", "void", "Relax.Console", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			if (Args::contains("-iostd"))
				std::cout << dynamic_cast<RelaxFloat*>(stack.pop())->GetData();
			else
				qout << QString::number(dynamic_cast<RelaxFloat*>(stack.pop())->GetData());
			return nullptr;
		},AccessModifier::PUBLIC, true),

		StdMethod("Read", "Relax.String", "Relax.Console", {}, [&](Stack& stack) -> Object*
		{
			QString str;
			qin >> str;
			return new RelaxString(str);
		},AccessModifier::PUBLIC, true)
	}));

	/* String */
	push_back(StdClass("Relax.String", {}));

	/* Array */
	push_back(StdClass("Relax.Array", {}));

	/* Int32 */
	push_back(StdClass("Relax.Int32", {
		/* operator== */
		StdMethod("operator==", "Relax.Bool", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			RelaxInt32* other = dynamic_cast<RelaxInt32*>(stack.pop());
			
			bool isEqual = thisObject->GetData() == other->GetData();
			RelaxBool* returnValue = new RelaxBool(isEqual);
			return returnValue;
		},AccessModifier::PUBLIC, false),

		/* operator+ */
		StdMethod("operator+", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			RelaxInt32* other = dynamic_cast<RelaxInt32*>(stack.pop());

			int result = thisObject->GetData() + other->GetData();
			RelaxInt32* returnValue = new RelaxInt32(result);
			return returnValue;
		},AccessModifier::PUBLIC, false),

		StdMethod("operator+", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			RelaxFloat* other = dynamic_cast<RelaxFloat*>(stack.pop());

			int result = thisObject->GetData() + other->GetData();
			RelaxInt32* returnValue = new RelaxInt32(result);
			return returnValue;
		},AccessModifier::PUBLIC, false),

		/* operator- */
		StdMethod("operator-", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			RelaxInt32* other = dynamic_cast<RelaxInt32*>(stack.pop());

			int result = thisObject->GetData() - other->GetData();
			RelaxInt32* returnValue = new RelaxInt32(result);
			return returnValue;
		},AccessModifier::PUBLIC, false),

		StdMethod("operator-", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			RelaxFloat* other = dynamic_cast<RelaxFloat*>(stack.pop());

			int result = thisObject->GetData() - other->GetData();
			RelaxInt32* returnValue = new RelaxInt32(result);
			return returnValue;
		},AccessModifier::PUBLIC, false),
		
		/* operator* */
		StdMethod("operator*", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			RelaxInt32* other = dynamic_cast<RelaxInt32*>(stack.pop());

			int result = thisObject->GetData() * other->GetData();
			RelaxInt32* returnValue = new RelaxInt32(result);
			return returnValue;
		},AccessModifier::PUBLIC, false),

		StdMethod("operator*", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			RelaxFloat* other = dynamic_cast<RelaxFloat*>(stack.pop());

			int result = thisObject->GetData() * other->GetData();
			RelaxInt32* returnValue = new RelaxInt32(result);
			return returnValue;
		},AccessModifier::PUBLIC, false),

		/* operator/ */
		StdMethod("operator/", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			RelaxInt32* other = dynamic_cast<RelaxInt32*>(stack.pop());

			int result = thisObject->GetData() / other->GetData();
			RelaxInt32* returnValue = new RelaxInt32(result);
			return returnValue;
		},AccessModifier::PUBLIC, false),

		StdMethod("operator/", "Relax.Int32", "Relax.Int32", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			RelaxFloat* other = dynamic_cast<RelaxFloat*>(stack.pop());

			int result = thisObject->GetData() / other->GetData();
			RelaxInt32* returnValue = new RelaxInt32(result);
			return returnValue;
		},AccessModifier::PUBLIC, false),
	}));

	/* Float */
	push_back(StdClass("Relax.Float", {
		
		/* operator== */
		StdMethod("operator==", "Relax.Bool", "Relax.Float", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			RelaxFloat* other = dynamic_cast<RelaxFloat*>(stack.pop());

			bool isEqual = thisObject->GetData() == other->GetData();
			RelaxBool* returnValue = new RelaxBool(thisObject->GetData() == other->GetData());
			return returnValue;
		},AccessModifier::PUBLIC, false),

		/* operator+ */
		StdMethod("operator+", "Relax.Float", "Relax.Float", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			RelaxFloat* other = dynamic_cast<RelaxFloat*>(stack.pop());

			float result = thisObject->GetData() + other->GetData();
			RelaxFloat* returnValue = new RelaxFloat(result);
			return returnValue;
		},AccessModifier::PUBLIC, false),

		StdMethod("operator+", "Relax.Float", "Relax.Float", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			RelaxInt32* other = dynamic_cast<RelaxInt32*>(stack.pop());

			float result = thisObject->GetData() + other->GetData();
			RelaxFloat* returnValue = new RelaxFloat(result);
			return returnValue;
		},AccessModifier::PUBLIC, false),

		/* operator- */
		StdMethod("operator-", "Relax.Float", "Relax.Float", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			RelaxFloat* other = dynamic_cast<RelaxFloat*>(stack.pop());

			float result = thisObject->GetData() - other->GetData();
			RelaxFloat* returnValue = new RelaxFloat(result);
			return returnValue;
		},AccessModifier::PUBLIC, false),

		StdMethod("operator-", "Relax.Float", "Relax.Float", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			RelaxInt32* other = dynamic_cast<RelaxInt32*>(stack.pop());

			float result = thisObject->GetData() - other->GetData();
			RelaxFloat* returnValue = new RelaxFloat(result);
			return returnValue;
		},AccessModifier::PUBLIC, false),

		/* operator* */
		StdMethod("operator*", "Relax.Float", "Relax.Float", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			RelaxFloat* other = dynamic_cast<RelaxFloat*>(stack.pop());

			float result = thisObject->GetData() * other->GetData();
			RelaxFloat* returnValue = new RelaxFloat(result);
			return returnValue;
		},AccessModifier::PUBLIC, false),

		StdMethod("operator*", "Relax.Float", "Relax.Float", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			RelaxInt32* other = dynamic_cast<RelaxInt32*>(stack.pop());

			float result = thisObject->GetData() * other->GetData();
			RelaxFloat* returnValue = new RelaxFloat(result);
			return returnValue;
		},AccessModifier::PUBLIC, false),

		/* operator/ */
		StdMethod("operator/", "Relax.Float", "Relax.Float", {Parameter("Relax.Float")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			RelaxFloat* other = dynamic_cast<RelaxFloat*>(stack.pop());

			float result = thisObject->GetData() / other->GetData();
			RelaxFloat* returnValue = new RelaxFloat(result);
			return returnValue;
		},AccessModifier::PUBLIC, false),

		StdMethod("operator/", "Relax.Float", "Relax.Float", {Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxFloat* thisObject = dynamic_cast<RelaxFloat*>(stack.pop());
			RelaxInt32* other = dynamic_cast<RelaxInt32*>(stack.pop());

			float result = thisObject->GetData() / other->GetData();
			RelaxFloat* returnValue = new RelaxFloat(result);
			return returnValue;
		},AccessModifier::PUBLIC, false),
	}));


	/* Random */
	push_back(StdClass("Relax.Random", {
		/* GererateInt32 */
		StdMethod("GenerateInt32", "Relax.Int32", "Relax.Random", {}, [&](Stack& stack) -> Object*
		{
			return RelaxRandom::GenerateInt32();
		},AccessModifier::PUBLIC, true),

		StdMethod("GenerateInt32", "Relax.Int32", "Relax.Random", {Parameter("Relax.Int32"), Parameter("Relax.Int32")}, [&](Stack& stack)->Object*
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
