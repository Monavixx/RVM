#include "ClassList.h"

ClassList::ClassList(const std::unordered_map<String, Class*>& classList) : std::unordered_map<String, Class*>(classList)
{
}

ClassList::ClassList(const ClassList& classList) : std::unordered_map<String, Class*>(classList)
{
}