#include "ClassList.h"

ClassList::ClassList()
{
}

ClassList::ClassList(const vector<Class*>& classList) : std::vector<Class*>(classList)
{
}

ClassList::ClassList(const ClassList& classList) : std::vector<Class*>(classList)
{
}

Class* ClassList::FindClassByName(const String& name)
{
	auto classIterator = std::find_if(this->begin(), this->end(), [&](Class* _class) {
		return _class->GetName() == name;
	});
	if(classIterator == this->end())
		return nullptr;
	return *classIterator;
}
