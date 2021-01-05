#include "StdClassList.h"

StdClassList::StdClassList()
{
}

StdClassList::StdClassList(const QList<StdClass>& stdClassList)
{
	this->clear();
	for (auto& item : stdClassList)
	{
		this->push_back(item);
	}
}

StdClassList::StdClassList(const StdClassList& stdClassList)
{
	this->clear();
	for (auto& item : stdClassList)
	{
		this->push_back(item);
	}
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

StdClassList& StdClassList::GetInstance()
{
	return stdClassList;
}
