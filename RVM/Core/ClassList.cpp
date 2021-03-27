#include "ClassList.h"
#include "FieldObject.h"

ClassList::ClassList(const std::unordered_map<String, Class*>& classList) : std::unordered_map<String, Class*>(classList)
{
}

ClassList::ClassList(const ClassList& classList) : std::unordered_map<String, Class*>(classList)
{
}

void ClassList::CreateStdClasses()
{
	RelaxConsole::GenerateMetaInfo();
	RelaxArray::GenerateMetaInfo();
	RelaxRandom::GenerateMetaInfo();
	RelaxConverter::GenerateMetaInfo();
	Object::GenerateMetaInfo();

	AddClass(RelaxConsole::metaClass);
	AddClass(RelaxArray::metaClass);
	AddClass(RelaxRandom::metaClass);
	AddClass(RelaxConverter::metaClass);
	AddClass(Object::metaClass);
}
