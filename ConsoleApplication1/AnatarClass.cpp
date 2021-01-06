#include "AnatarClass.h"

AnatarClass::AnatarClass(char* name) :name(name)
{
}

void AnatarClass::SetName(char* name)
{
	this->name = name;
}

char* AnatarClass::GetName() const
{
	return this->name;
}
