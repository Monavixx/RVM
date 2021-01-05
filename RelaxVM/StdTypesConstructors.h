#pragma once
#include "Object.h"
#include "Parameter.h"
#include "Stack.h"
#include "RelaxString.h"
#include "Functions/Exit.h"

class StdTypesConstructors
{
public:
	static Object* CreateObject(const QString& dataType, const QList<Parameter>& parameters, Stack& stack)
	{
		QString signature = dataType + "(";
		for (int i = 0; i < parameters.size(); ++i)
		{
			signature += parameters[i].GetDataType();
			if (i != parameters.size() - 1)signature += ",";
		}
		signature += ")";

		if(constructions.contains(signature))
			return constructions[signature](stack);

		Exit("Construction not exists");
	}

	static inline QMap<QString, std::function<Object* (Stack&)>> constructions =
	{
		{
			"Relax.String(Relax.String)", [&](Stack& stack) -> Object*
			{
				Variable* otherString = stack.pop();
				QString data = dynamic_cast<RelaxString*>(otherString->GetData())->GetData();
				return new RelaxString(data);
			}
		}
	};
};

