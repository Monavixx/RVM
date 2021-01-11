#include "StdClassList.h"

StdClassList::StdClassList()
{
	push_back(StdClass("Relax.Console", {
		StdMethod("Write", "void", "Relax.Console", QList<Parameter>{Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			qout << dynamic_cast<RelaxString*>(stack.pop())->GetData();
			return nullptr;
		},AccessModifier::PUBLIC, true),

		StdMethod("Write", "void", "Relax.Console", QList<Parameter>{Parameter("Relax.Int32")}, [&](Stack& stack) -> Object*
		{
			qout << QString::number(dynamic_cast<RelaxInt32*>(stack.pop())->GetData());
			return nullptr;
		},AccessModifier::PUBLIC, true)
	}));

	push_back(StdClass("Relax.String", {
		StdMethod("Relax.String", "Relax.String", "Relax.String", QList<Parameter>{Parameter("Relax.String")}, [&](Stack& stack) -> Object*
		{
			RelaxString* data = dynamic_cast<RelaxString*>(stack.pop());
			RelaxString* newData = new RelaxString(data->GetData());
			return newData;
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
