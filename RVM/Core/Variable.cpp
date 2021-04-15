#include "Variable.h"
#include "FieldObject.h"
#include "Class.h"
#include "Namespace.h"

String Variable::GetDataType() const
{
	return dataType->GetNamespace()->GetName() + '.' + dataType->GetName();
}