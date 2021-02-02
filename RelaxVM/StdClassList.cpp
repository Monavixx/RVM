#include "StdClassList.h"

StdClassList::StdClassList()
{
	push_back(StdClass("Relax.Console", {
		StdMethod("Write", "void", "Relax.Console", QList<Parameter>{Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			if(Args::args.contains("-iostd"))
				std::cout << dynamic_cast<RelaxString*>(stack.pop())->GetData().toStdString();
			else
				qout << dynamic_cast<RelaxString*>(stack.pop())->GetData();
			return nullptr;
		},AccessModifier::PUBLIC, true),

		StdMethod("Write", "void", "Relax.Console", QList<Parameter>{Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			if (Args::args.contains("-iostd"))
				std::cout << dynamic_cast<RelaxInt32*>(stack.pop())->GetData();
			else
				qout << QString::number(dynamic_cast<RelaxInt32*>(stack.pop())->GetData());
			return nullptr;
		},AccessModifier::PUBLIC, true)
	}));

	push_back(StdClass("Relax.String", {}));

	push_back(StdClass("Relax.Array", {}));

	push_back(StdClass("Relax.Int32", {
		StdMethod("operator==", "Relax.Bool", "Relax.Int32", QList<Parameter>{Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			RelaxInt32* other = dynamic_cast<RelaxInt32*>(stack.pop());
			RelaxInt32* thisObject = dynamic_cast<RelaxInt32*>(stack.pop());
			
			bool isEqual = thisObject->GetData() == other->GetData();
			RelaxBool* returnValue = new RelaxBool(thisObject->GetData() == other->GetData());
			return returnValue;
		},AccessModifier::PUBLIC, false)
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
