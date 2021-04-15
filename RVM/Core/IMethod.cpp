#include "IMethod.h"
#include "Class.h"

bool IMethod::operator==(IMethod& other) const
{
	if (isStatic != other.isStatic) return false;
	if (name != other.name) return false;
	if (declClass != other.declClass) return false;
	if (dataType != other.dataType) return false;
	if (parameters != other.parameters) return false;
	if (accessModifier != other.accessModifier) return false;
	return true;
}
