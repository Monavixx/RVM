#include "ClassList.h"

ClassList::ClassList(const std::unordered_map<String, Class*>& classList) : std::unordered_map<String, Class*>(classList)
{
}

ClassList::ClassList(const ClassList& classList) : std::unordered_map<String, Class*>(classList)
{
}

void ClassList::CreateStdClasses()
{
	RelaxConsole::GenerateMetaInfo();
	RelaxString::GenerateMetaInfo();
	RelaxArray::GenerateMetaInfo();
	RelaxInt32::GenerateMetaInfo();
	RelaxFloat::GenerateMetaInfo();
	RelaxRandom::GenerateMetaInfo();
	RelaxConverter::GenerateMetaInfo();
	Object::GenerateMetaInfo();

	AddClass(RelaxConsole::metaClass);
	AddClass(RelaxString::metaClass);
	AddClass(RelaxArray::metaClass);
	AddClass(RelaxInt32::metaClass);
	AddClass(RelaxFloat::metaClass);
	AddClass(RelaxRandom::metaClass);
	AddClass(RelaxConverter::metaClass);
	AddClass(Object::metaClass);
}
