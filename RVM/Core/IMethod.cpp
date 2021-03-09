#include "IMethod.h"

String IMethod::ToString() const
{
	String signature;
	signature += dataType + " " + declClassName + "." + name + "(";
	for (size_t i = 0; i < parameters.size(); ++i)
	{
		signature += parameters[i].GetDataType();
		if (i != parameters.size() - 1)
			signature += ",";
	}
	signature += ")";
	return signature;
}

bool IMethod::operator==(IMethod& other) const
{
	if (isStatic != other.isStatic) return false;
	if (name != other.name) return false;
	if (declClassName != other.declClassName) return false;
	if (dataType != other.dataType) return false;
	if (parameters != other.parameters) return false;
	if (accessModifier != other.accessModifier) return false;
	return true;
}
