#include "StdClassList.h"

StdClassList::StdClassList()
{
	RelaxConsole::GenerateMetaInfo();
	RelaxString::GenerateMetaInfo();
	RelaxArray::GenerateMetaInfo();
	RelaxInt32::GenerateMetaInfo();
	RelaxFloat::GenerateMetaInfo();
	RelaxRandom::GenerateMetaInfo();
	RelaxConverter::GenerateMetaInfo();

	AddClass(RelaxConsole::metaClass);
	AddClass(RelaxString::metaClass);
	AddClass(RelaxArray::metaClass);
	AddClass(RelaxInt32::metaClass);
	AddClass(RelaxFloat::metaClass);
	AddClass(RelaxRandom::metaClass);
	AddClass(RelaxConverter::metaClass);
}


void StdClassList::AddClass(StdClass* stdClass)
{
	operator[](stdClass->GetName()) = stdClass;
}


StdClassList* StdClassList::GetInstance()
{
	if (stdClassList == nullptr) stdClassList = new StdClassList;
	return stdClassList;
}