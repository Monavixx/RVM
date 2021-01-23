#include "ClassList.h"

ClassList::ClassList()
{
}

ClassList::ClassList(const QList<Class>& classList)
{
	this->clear();
	for (auto& item : classList)
	{
		this->push_back(item);
	}
}

ClassList::ClassList(const ClassList& classList)
{
	this->clear();
	for (auto& item : classList)
	{
		this->push_back(item);
	}
}

Class* ClassList::FindClassByName(const QString& name)
{
	auto classIterator = std::find_if(this->begin(), this->end(), [&](const Class& _class) {
		return _class.GetName() == name;
	});
	if(classIterator == this->end())
		return nullptr;
	return &(*classIterator);
}
