#include "StdClassList.h"

StdClassList::StdClassList()
{
	push_back(StdClass("Relax.Console", {
		StdMethod("Write", "void", "Relax.Console", QList<Parameter>{Parameter("text", "Relax.String")}, [&](Stack& stack)
		{
			qout << dynamic_cast<RelaxString*>(stack.pop())->GetData();
			return nullptr;
		},AccessModifier::PUBLIC, true)
	}));

	push_back(StdClass("Relax.String", {
		StdMethod("Relax.String", "Relax.String", "Relax.String", QList<Parameter>{Parameter("other", "Relax.String")}, [&](Stack& stack)
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
