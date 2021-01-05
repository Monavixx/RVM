#include "StdClassList.h"

StdClassList::StdClassList()
{
	push_back(StdClass("Relax.Console", {
		StdMethod("Write", "void", "Relax.Console", QList<Parameter>{Parameter("text", "Relax.String")}, [&](Stack& stack)
		{
			qout << dynamic_cast<RelaxString*>(stack.pop()->GetData())->GetData();
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
